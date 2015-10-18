---
title: School exercise environment
layout: main
---

The goal of this step is to get confident with the ESC working
environment and checking that everything is correctly set up for the
school exercises.

If something doesn't work as expected, please ask one of the
organizers.

Wi-Fi access
------------

Make sure you are using the INFN-Captive WiFi or eduroam networks and
not the CEUB WiFi network. Only the INFN-Captive or eduroam networks
will work for the following.

SSH access to school computers
------------------------------

You have been assigned a personal account, with a username of the
form studentNM, where nm is a number between 01 and 30. In the
following, when you see studentNM, replace it with your personal
account. You should also have received the corresponding
password.

Similarly you have been assigned a personal host, named esc-XY, where
xy is a number between 01 and 60. In the following, when you see
esc-XY, replace it with the name of the host assigned to you.

You were also assigned two virtual machines (with names of the form
`esc-vm-xyz`). However, for the exercises in this section you do not (and 
should not) use the 
virtual machines. Use the real server (with a name of the form
`esc-XY`).

To log on esc-XY you have to first log on a gateway server, named
esc-gw.pd.infn.it, with the username and password of studentNM

	[myself@mylaptop ~]$ ssh -X studentNM@esc-gw.pd.infn.it

The -X option forwards the X11 display.

From there you can log onto esc-XY in a password-less way, thanks to an SSH
key already generated for you and available in the .ssh directory
(files id_rsa and id_rsa.pub).

	[studentNM@esc-gw ~]$ ssh esc-XY

You can do it in one step:

	[myself@mylaptop ~]$ $ ssh -t studentNM@esc-gw ssh esc-XY

If you wish, you can copy the SSH credential files onto your personal
laptop, so that you can log on esc-gw without password. If you run
Linux on your laptop, a convenient setup may be the following:

	[myself@mylaptop ~]$ mkdir esc_ssh
	[myself@mylaptop ~]$ scp studentNM@esc-gw.pd.infn.it:.ssh/id_rsa esc_ssh
	[myself@mylaptop ~]$ scp studentNM@esc-gw.pd.infn.it:.ssh/id_rsa.pub esc_ssh
	[myself@mylaptop ~]$ chmod 600 esc_ssh/id_rsa
	[myself@mylaptop ~]$ cat >> .ssh/config <<EOF
	Host esc-gw
	HostName esc-gw.pd.infn.it
	User studentNM
	IdentityFile ~/esc_ssh/id_rsa
	EOF
	[myself@mylaptop ~]$ mkdir esc_mnt
	[myself@mylaptop ~]$ sshfs esc-gw: esc_mnt

Your shell is [`bash`](http://www.gnu.org/s/bash)

Your home directory is shared between esc-gw and esc-XY, but
please don't use esc-gw but for logging into esc-XY.

<div class="alert alert-danger" role="alert">
<strong>IMPORTANT NOTE:</strong> The student computers will be uninstalled on Friday
evening and all data on them will be destroyed. Please make sure you make
a copy of everything valuable by the end of the Friday session!
</div>


School material
---------------

The school material is all included in a git repository. Get it using:

	git clone https://github.com/infn-esc/esc15.git

Testing the environment
-----------------------

1. Log onto your student host

2. Check the following commands and the respective outputs:

		[studentNM@esc-XY ~]$ c++ -dumpversion
		5.2.0
		[studentNM@esc-XY ~]$ valgrind --version
		valgrind-3.10.0
		[studentNM@esc-XY ~]$ igprof -h
		igprof [options] program [options]
		
		Options to igprof:
		-h, --help                  	this help message
		...
		[studentNM@esc-XY ~]$ which igprof-navigator
		/usr/bin/igprof-navigator

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

Editing source code
-------------------

On esc-XY you can find several editors available, such as vim, emacs,
gedit, nano. If your laptop's diplay is available, graphical editors
will open a window on your laptop; the network latency however may not
be good enough to give you a fine experience.

Alternatively you could edit the source code for the exercises on your
laptop, synchronizing the files with esc-XY. In the following some
options are presented.

Using sshfs
===========

You can mount your home directory on the ESC system on your laptop via
sshfs.

	[myself@mylaptop ~]$ mkdir esc
	[myself@mylaptop ~]$ sshfs 
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
