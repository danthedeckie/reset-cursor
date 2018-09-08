# reset-cursor
(Windows) Move the mouse back when it gets lost.

Written in C, compiled with tcc to try and make it as small, fast, and light as possible.

You can create a short-cut to it on your desktop, and then in the shortcut
properties assign a keyboard-shortcut to it, say `"ctrl-alt-m"`, and then
globally, anywhere in any application if you lose the mouse, press that and
it will re-appear where you want it to.

To control where you want the mouse to re-appear, add an `x` and `y` co-ordinate
to the end of the command-line.

Eg:

`reset-cursor.exe 100 100`

## to compile it

You'll need [tcc](https://download.savannah.gnu.org/releases/tinycc/), and the tcc full windows api downloaded.

Then it's just

`tcc.exe reset-cursor.c -lshell32`

and ta da! Done.

## Slow global shortcuts.

I initially wrote this in Python, but the various other computers at work
I wanted it in didn't have python, I re-wrote it in powershell.  But on
running `'ctrl-alt-m'`, it would sometimes be 3 or 4 seconds before it
actually did anything, which was unacceptable.  So I downloaded tcc, and
re-wrote it again.  And sometimes, it would still take a few seconds.  Although
running the exe or shortcut directly was instant.  Wat?  Apparently Windows
Is Like That.  Opening up the 'Privacy Settings' makes it suddenly back to
instant again.  Apparently turning off some background applications can
make global shortcuts work instantly rather than windows deciding to sit
around and wait to ask them all what they think of it before actually running
anything.

So, it's possible that making a helper service that somehow inspected every single
keypress in windows would actually be faster than running a shortcut.  But whatever.

This works for me for now.
