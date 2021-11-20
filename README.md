# MediaOsdToggle

This is a tiny windows executable that will toggle the Windows Media OSD visibility.  I personally can't stand that 
damn OSD thing. Once it does its job it exits so there is nothing running in the background.

Every time you run the app it will toggle the OSD visibility.  It will check to see if it is already hidden, and if so 
make it visible again. If not it will hide it. That is all it does. There are no options, tray icons, windows or 
configuration involved.  

There is no installer for this application since it is a single Windows executable.  Just put it wherever you want 
it and run it.  I have it hooked up to a keyboard shortcut using AutoHotKey so that I can toggle it for the rare 
occasion I want to see the OSD.

If you are just downloading the release executable you will need the latest Microsoft Visual C++ Redistributable if 
you don't have it already.  You can check if you already have it by just running the application.  If you don't have the runtime a 
dialog will pop up telling you that it is missing.  If that happens the runtime can be downloaded directly from 
[here](https://aka.ms/vs/17/release/vc_redist.x64.exe) or navigate to
https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0
and select the x64 download.

I prefer to use Cmake vs Visual Studio solution files so that I can use other IDEs (e.g. Visual Studio Code or CLion)
to write my Windows applications.  The full Visual Studio install is pretty big so when I am on the move I use Visual 
Studio Code on my Surface Laptop since it is low on power and disk space.

If you want to build it you need to make sure you have Visual Studio 2022 with the cmake tools installed.  Otherwise, 
you can download cmake and the VC build tools manually to build it.

