# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.arkanoid.Debug:
PostBuild.glfw.Debug: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/arkanoid.app/Contents/MacOS/arkanoid
PostBuild.glad.Debug: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/arkanoid.app/Contents/MacOS/arkanoid
PostBuild.glfw.Debug: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/arkanoid.app/Contents/MacOS/arkanoid
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/arkanoid.app/Contents/MacOS/arkanoid:\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Debug/libglfw3.a\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/libglad.a\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Debug/libglfw3.a
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/arkanoid.app/Contents/MacOS/arkanoid


PostBuild.glad.Debug:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/libglad.a:
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/libglad.a


PostBuild.glfw.Debug:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Debug/libglfw3.a:
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Debug/libglfw3.a


PostBuild.arkanoid.Release:
PostBuild.glfw.Release: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/arkanoid.app/Contents/MacOS/arkanoid
PostBuild.glad.Release: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/arkanoid.app/Contents/MacOS/arkanoid
PostBuild.glfw.Release: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/arkanoid.app/Contents/MacOS/arkanoid
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/arkanoid.app/Contents/MacOS/arkanoid:\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Release/libglfw3.a\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/libglad.a\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Release/libglfw3.a
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/arkanoid.app/Contents/MacOS/arkanoid


PostBuild.glad.Release:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/libglad.a:
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/libglad.a


PostBuild.glfw.Release:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Release/libglfw3.a:
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Release/libglfw3.a


PostBuild.arkanoid.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/arkanoid.app/Contents/MacOS/arkanoid
PostBuild.glad.MinSizeRel: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/arkanoid.app/Contents/MacOS/arkanoid
PostBuild.glfw.MinSizeRel: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/arkanoid.app/Contents/MacOS/arkanoid
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/arkanoid.app/Contents/MacOS/arkanoid:\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/libglad.a\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/arkanoid.app/Contents/MacOS/arkanoid


PostBuild.glad.MinSizeRel:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/libglad.a:
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/libglad.a


PostBuild.glfw.MinSizeRel:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a


PostBuild.arkanoid.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/arkanoid.app/Contents/MacOS/arkanoid
PostBuild.glad.RelWithDebInfo: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/arkanoid.app/Contents/MacOS/arkanoid
PostBuild.glfw.RelWithDebInfo: /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/arkanoid.app/Contents/MacOS/arkanoid
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/arkanoid.app/Contents/MacOS/arkanoid:\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/libglad.a\
	/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/arkanoid.app/Contents/MacOS/arkanoid


PostBuild.glad.RelWithDebInfo:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/libglad.a:
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/libglad.a


PostBuild.glfw.RelWithDebInfo:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a




# For each target create a dummy ruleso the target does not have to exist
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Debug/libglad.a:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/MinSizeRel/libglad.a:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/RelWithDebInfo/libglad.a:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/Release/libglad.a:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Debug/libglfw3.a:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/MinSizeRel/libglfw3.a:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
/Users/carlypresz/Desktop/Graphics\ Github/final-project-team-yoshi/Arkanoids!/build/glfw-3.2/src/Release/libglfw3.a:
