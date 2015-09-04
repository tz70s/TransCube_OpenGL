## TransCube_OpenGL
* OpenGL implementation

####Environment Construction

======================================================================================================================

```
  main.cpp
``` 
* Doing the Windows Initialization , linking to computation files and data files.
* Making the links from shaders(GLSL script file), and the buffers.

```
  Utils.cpp Utils.h
```
* Doing the Matrix computation.
* Using the struct to call.
* The following function have Translate , RotateAboutX , RotateAboutY , RotateAboutZ , Scale.
```
  shader_load.cpp shader_load.o
```
* Doing the shader(GLSL script file) load and construct the shader objects link to the main file.
* Link to vertex.vs , fragment.fs as Vertecies Shaders (Construct the shape) and Fragment Shaders (Colors and Material Texture).

``` 
  GUI interface
```
```
  Music Analyzer
``` 
analyze music equalizer , and send dynamic data of the music data stream.</br>

======================================================================================================================

### Experiment 1

* Doing quads extenting in Z way , as music equalizer change.
* Following files
  * vertices file
    * storing the quads vertices and indices , sending to main file to render.
  * motion controll file(class)
    * link to music analyzer to do the controll.
    * first test only motion controll by frame_time.

=====================================================================================================================

### Experiment 2

* Doing quad's suface scratching and doing the equalizer cutoff.
* Following files
  * vertices file
    * as Exp1.
  * motion controll
    * add mouse controll to pull surface of quad.
  * cutoff function
    * doing equalizer cut off and link to motion controll file



