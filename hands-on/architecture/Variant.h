#ifndef Variant_H
#define Variant_H


#include<cmath>
#include<tuple>
#include<functional>
#include<type_traits>
#include <cstring>
#include <cassert>


namespace any_details {

  template<typename T>
  inline constexpr T vmax(T a, T b) { return (a>b) ? a : b;}
  
  template<class TupleType, int N=std::tuple_size<TupleType>::value>
  struct maxSizeT {
    typedef typename std::tuple_element<N-1,TupleType>::type Elem;
    enum { valueSize = vmax(sizeof(Elem), (long unsigned int)(maxSizeT<TupleType,N-1>::valueSize)),
	   valueAlign = vmax(alignof(Elem), (long unsigned int)(maxSizeT<TupleType,N-1>::valueAlign)) };
  };
  
  template<class TupleType>
  struct maxSizeT<TupleType, 0>  {
    enum  { valueSize = sizeof(typename std::tuple_element<0,TupleType>::type),
	    valueAlign = alignof(typename std::tuple_element<0,TupleType>::type)};
  };
  

  template <typename TupleType, typename S, int i = std::tuple_size<TupleType>::value - 1>
  struct tuple_index
  {
    enum
      {
        value = std::is_same<typename std::tuple_element<i, TupleType>::type, S>::value ?
	i :
	tuple_index<TupleType, S, i-1>::value
      };
  };
  
  template <typename TupleType, typename S>
  struct tuple_index<TupleType, S, -1>
  {
    enum { value = -1 };
  };
  
  template<class Head, typename ... Tail>
struct maxSize {
    enum { valueSize = vmax(sizeof(Head), (long unsigned int)(maxSize<Tail...>::valueSize)),
	   valueAlign = vmax(alignof(Head), (long unsigned int)(maxSize<Tail...>::valueAlign)),
    };
  };

  template<class T>
  struct maxSize<T>  {
    enum  { valueSize = sizeof(T),valueAlign = alignof(T) };
  };
  
}
  

template<typename...C>
struct Variant {
  // using aligned_union_t = typename std::aligned_union<8,C...>::type;
  enum { size = any_details::maxSize<C...>::valueSize, align = any_details::maxSize<C...>::valueAlign};
  using aligned_union_t = typename std::aligned_storage<size,align>::type;


  Variant() {}

  bool empty() { return m_index<0;}

  template<typename T>
  struct Deleter {
    static void destroy(void * t) { ((T*)(t))->~T();}
  };

  using TT = std::tuple<C...>;
  // using DT = std::tuple<Deleter<C>...>;
  
 

  /* does not teally work
  template<typename T>
  struct Tag { using type=T;};  
  template<typename T, typename ... Args>
  Variant(T, Args&&... args){
    new(get()) typename T::type(std::forward<Args...>(args...));
  }
  */  

  void destroy() {if(m_index>=0) deleter(&mem);}

  template<typename T> 
  explicit Variant(T const & t) noexcept : 
  m_index(any_details::tuple_index<TT, T>::value),  
    deleter(Deleter<T>::destroy) {
    new(&mem) T(t); 
  }

  template<typename T> 
  explicit Variant(T && t)  noexcept :m_index(any_details::tuple_index<TT, T>::value), deleter(Deleter<T>::destroy) {
    new(&mem) T(std::move(t)); 
  }
  template<typename T> 
  void reset(T const & t) noexcept {
    destroy();
    m_index = any_details::tuple_index<TT, T>::value;
    deleter=Deleter<T>::destroy;
    new(&mem) T(t);
  }
  template<typename T> 
  void reset(T && t) noexcept {
    destroy();
    m_index = any_details::tuple_index<TT, T>::value;
    deleter=Deleter<T>::destroy;
    new(&mem) T(std::move(t)); 
  }
  
  Variant(Variant&&rh) noexcept : mem(std::move(rh.mem)),  m_index(rh.m_index),  deleter(std::move(rh.deleter)) { rh.m_index=-1;}

  Variant& operator=(Variant&&rh) noexcept {
    if ((&rh)==this) return *this;
    destroy();
    mem= std::move(rh.mem);
    deleter = std::move(rh.deleter);
    m_index=rh.m_index;  rh.m_index=-1;
    return *this;
  }
  
  ~Variant() { destroy(); }
  Variant(Variant const&) = delete;
  Variant& operator=(Variant const&) = delete; 
  
  template<typename T>
  T * get() { return (T*)&mem;}
  template<typename T>  
  T const * get() const { return (T* const)&mem;}
  template<typename T>
  T & operator()() { return *get(); }
  template<typename T>
  T const & operator()() const { return *get();}
  aligned_union_t mem;
  int m_index = -1;
  std::function<void(void *)> deleter;
};

#endif
