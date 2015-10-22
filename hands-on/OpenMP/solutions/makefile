#
#  USAGE:
#     make          ... to build the program
#     make test     ... to run the default test case
#
include ../make.def

EXES=hello_par$(EXE) pi_spmd_simple$(EXE) pi_spmd_final$(EXE) \
     pi_loop$(EXE) mandel_par$(EXE) pi_task$(EXE)  \
     mm_testbed$(EXE) jac_solv_parfor jac_solv_par_for$(EXE) \
     stencil_par$(EXE) racey_tasks$(EXE)

MM_OBJS  = mm_testbed.$(OBJ) mm_utils.$(OBJ) mm_tst_cases.$(OBJ) \
           mm_ijk.$(OBJ) mm_ikj.$(OBJ) mm_ikj_par.$(OBJ) mm_trans.$(OBJ)

STN_PAR_OBJS  = stencil_par.$(OBJ)  

JAC_PAR_FOR_OBJS  = jac_solv_par_for.$(OBJ) mm_utils.$(OBJ) 

JAC_PARFOR_OBJS  = jac_solv_parfor.$(OBJ) mm_utils.$(OBJ) 

all: $(EXES)

stencil_par$(EXE): $(STN_PAR_OBJS) 
	$(CLINKER) $(CFLAGS) -o stencil_par$(EXE) $(STN_PAR_OBJS) $(LIBS)

jac_solv_par_for$(EXE): $(JAC_PAR_FOR_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv_par_for$(EXE) $(JAC_PAR_FOR_OBJS) $(LIBS)

jac_solv_parfor$(EXE): $(JAC_PARFOR_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv_parfor$(EXE) $(JAC_PARFOR_OBJS) $(LIBS)

mm_testbed$(EXE): $(MM_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o mm_testbed$(EXE) $(MM_OBJS) $(LIBS)

hello_par$(EXE): hello_par.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o hello_par$(EXE) hello_par.$(OBJ) $(LIBS)

pi_spmd_simple$(EXE): pi_spmd_simple.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_simple$(EXE) pi_spmd_simple.$(OBJ) $(LIBS)

pi_spmd_final$(EXE): pi_spmd_final.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_final$(EXE) pi_spmd_final.$(OBJ) $(LIBS)

pi_loop$(EXE): pi_loop.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_loop$(EXE) pi_loop.$(OBJ) $(LIBS)

mandel_par$(EXE): mandel_par.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o mandel_par$(EXE) mandel_par.$(OBJ) $(LIBS)

racey_tasks$(EXE): racey_tasks.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o racey_tasks$(EXE)  racey_tasks.$(OBJ) $(LIBS)

pi_task$(EXE): pi_task.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi_task$(EXE) pi_task.$(OBJ) $(LIBS)

test: $(EXES)
	for i in $(EXES); do \
            $(PRE)$$i; \
        done

clean:
	$(RM) $(EXES) *.$(OBJ)

.SUFFIXES:
.SUFFIXES: .c .cpp  .$(OBJ)

.c.$(OBJ):
	$(CC) $(CFLAGS) -c $<

.cpp.$(OBJ):
	$(CC) $(CFLAGS) -c $<
