---
title: School exercise environment
layout: main
---

The goal of this step is to prepare your working environment for the ESC
exercises.  At the end of this step you should have a reasonably workable
environment for running the other exercises.

You will work using the account created for you. In what follows we will
write `<student>` to indicate where you should substitute the username you
were assigned.

  * You were assigned a host between `esc-01` and `-39` to work on. One
    student is assigned to each server. 
  * You were also assigned two virtual machines (with names of the form
    `esc-vm-xyz`). However, for the exercises in this section you do not (and 
    should not) use the 
    virtual machines. Use the real server (with a name of the form `esc-xy`).
  * Your home directory is `/export/students-home/<student>` and is local 
    to the server, where `<student>` is your assigned login name
  * Your shell is [`bash`](http://www.gnu.org/s/bash)

Below we use *`<student>`* as a general student account `esc-server-<nn>` as the
general host alias.  When executing the commands, replace these with the
account name or host assigned to you.  

**IMPORTANT NOTE:** *The student computers will be uninstalled on Friday
evening and all data on them will be destroyed. Please make sure you make
a copy of everything valuable by the end of the Friday session!*


Simple configuration
--------------------

This is the minimal basic configuration you should follow at the very least.
If you are working on Mac OS X or Linux laptop and moderately comfortable
with SSH and would rather you use the editor on your local system, the more
advanced steps below give an alternate extended configuration which makes
working somewhat nicer and easier.

0. Make sure you are using the INFN-Captive WiFi or eduroam networks and not the CEUB
   WiFi network. Only the INFN-Captive or eduroam networks will work for the following. If
   you do not have a user/pass to connect to the INFN-Captive network 
   (and cannot connect to the eduroam network), ask one of the organizers.

1. First SSH into the gateway/NSF/Apache server (`esc-server.cnaf.infn.it`):
     
        ssh <student>@131.154.193.33

2. You can only connect out to github from this gateway server, but it
   has the same home area. Get the school exercises material:

        git clone https://github.com/infn-esc/esc15.git

   Notice that if you need to update this during the school, you will have to do it
   from this gateway server, not the assigned host.

 3. Then from there SSH into your assigned host:
 
        ssh <student>@esc-<nn>
        echo $HOME $SHELL
        ls -laF

Finishing off
-------------

1. Open one or more terminal windows and ssh into the student server, and
   in each of them run the following environment setup:

       gcc49cms   # Note the "cms"
       export SCRAM_ARCH=slc6_amd64_gcc490
       export VO_CMS_SW_DIR=/export/software/cms/
       . $VO_CMS_SW_DIR/$SCRAM_ARCH/external/valgrind/3.9.0/etc/profile.d/init.sh
       . $VO_CMS_SW_DIR/$SCRAM_ARCH/external/igprof/5.9.10/etc/profile.d/init.sh

2. Check the following are working ok:

       c++ -v 2>&1 | grep version  # should say 'gcc version 4.9.0 (GCC)'
       valgrind --version          # should say 'valgrind-3.10.0'
       igprof -h                   # should print simple help message
       which igprof-navigator      # should say full path

3. Create a web area where you will put output from some exercises:

       mkdir -p ~/public_html/cgi-bin/data
       cp $(which igprof-navigator) ~/public_html/cgi-bin/igprof-navigator.py
       echo "<html><body><a href='cgi-bin/igprof-navigator.py'>My" \
         "igprof reports</a></body></html>" > ~/public_html/index.html
       chmod 755 ~/public_html/cgi-bin

4. View `http://131.154.193.33/~<student>/` in your web browser, you
   should see the basic page you created above. Click on the link to
   profiles, it should produce some output -- for now it will in fact
   display an error message due to lack of profiles.

In subsequent exercises, you should have one more terminal windows open with
ssh session to the student server, and source the environment setup script as
shown below. **Always start each new exercise in a fresh new shell 
environment!**

If you are adventurous, you can build igprof standalone yourself following
the [recipe on the web site](http://igprof.sourceforge.net/install.html).

Advanced configuration
----------------------

The above should be sufficient for more purposes, however we also includes
notes on an alternate "advanced" configuration.

The assumption for this more advanced section is that you prefer to work on
your laptop, editing exercise code there. In parallel you will keep several
terminal windows open on the student server, where you compile code and run
other commands. We set up SSH keys so you can login to your server without
constantly typing your password, plus some convenient name aliases so you do
need to remember IP addresses.

1. SSH into your assigned host:

         ssh <student>@esc-<nn>
         echo $HOME $SHELL
         mkdir -p .ssh
         chmod 755 .ssh
         ls -laF

2. If your laptop is Linux, Mac OS X, or if you use Cygwin on Windows, we
   recommend you keep a copy of all your exercise source code, notes etc.
   locally, and `rsync <http://rsync.samba.org/>`_ to/from student servers.
   This ensures you keep a copy of everything relevant locally at the end.

   * Generate a temporary SSH key and copy it to the right host:

         ssh-keygen -t rsa -C esc15_temp_key -f ~/.ssh/id_rsa_esc15
         scp ~/.ssh/id_rsa_esc15.pub <student>@131.154.193.33:.ssh/authorized_keys

   * If not on OS X, start an `ssh-agent`:

         [ $(uname) != Darwin ] && { killall ssh-agent; eval `ssh-agent`; }

   * Add the just-generated key to your `ssh-agent`:

         ssh-add ~/.ssh/id_rsa_esc15

   * Test you can rsync to the student host (change "esc-40" below to your
     assigned node!):

         mkdir /tmp/foo
         date > /tmp/foo/test.txt
         rsync -av /tmp/foo/ 131.154.193.33:foo/
         ssh <student>@131.154.193.33 ls -laFR foo
         ssh <student>@131.154.193.33 rm -fr foo
         rm -fr /tmp/foo

3. Get the school exercises material on your laptop:

        cd <My/Dev/Area>
        git clone https://github.com/infn-esc/esc15.git

        # If you get SSL error, 'export GIT_SSL_NO_VERIFY=true' first.
        # The local firewall prevents use of 'git:' url style on your laptop.

4. Synchronise to your student server:

        rsync -av esc15/ 131.154.193.33:esc15/

   You can download a [zip file](https://github.com/infn-esc/esc15/zipball/master)
   or [tar ball](https://github.com/infn-esc/esc/tarball/master) from the
   [github web page](http://github.com/infn-esc/esc15) if you don't have `git`.

   You can now edit sources on your laptop, and run the command above to sync
   to the server. You can of course also run an editor on the server and sync
   back to your laptop, which ever you feel more comfortable with. Do be
   careful with rsync command syntax, however, it's easy to make mistakes.
