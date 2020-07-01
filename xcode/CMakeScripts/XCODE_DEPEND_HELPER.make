# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.glad.Debug:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/libglad.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/libglad.a


PostBuild.glfw.Debug:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/Debug/libglfw3.a


PostBuild.learn-opengl.Debug:
PostBuild.glad.Debug: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/learn-opengl
PostBuild.glfw.Debug: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/learn-opengl
PostBuild.glm.Debug: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/learn-opengl
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/learn-opengl:\
	/Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/libglad.a\
	/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/Debug/libglfw3.a
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/learn-opengl


PostBuild.glad.Release:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/libglad.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/libglad.a


PostBuild.glfw.Release:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/Release/libglfw3.a


PostBuild.learn-opengl.Release:
PostBuild.glad.Release: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/learn-opengl
PostBuild.glfw.Release: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/learn-opengl
PostBuild.glm.Release: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/learn-opengl
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/learn-opengl:\
	/Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/libglad.a\
	/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/Release/libglfw3.a
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/learn-opengl


PostBuild.glad.MinSizeRel:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/libglad.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/libglad.a


PostBuild.glfw.MinSizeRel:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/MinSizeRel/libglfw3.a


PostBuild.learn-opengl.MinSizeRel:
PostBuild.glad.MinSizeRel: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/learn-opengl
PostBuild.glfw.MinSizeRel: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/learn-opengl
PostBuild.glm.MinSizeRel: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/learn-opengl
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/learn-opengl:\
	/Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/libglad.a\
	/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/learn-opengl


PostBuild.glad.RelWithDebInfo:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/libglad.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/libglad.a


PostBuild.glfw.RelWithDebInfo:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/RelWithDebInfo/libglfw3.a


PostBuild.learn-opengl.RelWithDebInfo:
PostBuild.glad.RelWithDebInfo: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/learn-opengl
PostBuild.glfw.RelWithDebInfo: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/learn-opengl
PostBuild.glm.RelWithDebInfo: /Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/learn-opengl
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/learn-opengl:\
	/Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/libglad.a\
	/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/learn-opengl




# For each target create a dummy ruleso the target does not have to exist
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/Debug/libglad.a:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/MinSizeRel/libglad.a:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/RelWithDebInfo/libglad.a:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/Release/libglad.a:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/Debug/libglfw3.a:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/MinSizeRel/libglfw3.a:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/RelWithDebInfo/libglfw3.a:
/Users/giancedrickepilan/dev/native/learn-opengl/xcode/lib/glfw/src/Release/libglfw3.a:
