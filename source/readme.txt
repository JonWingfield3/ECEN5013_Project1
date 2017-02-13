Documentation for our makefile for project 1

Format
  make /command/
    - brief description of what said command will make

Replace file with the name of the file to be created
  make file.o
    - Will create the object file with the same name and store them in the obj
      folder.

  make file.i
    - Will create the preprocessed output file with the same name and store them
      in the misc folder.

  make file.asm
    - Will create the assembly output file with the same name and store it in
      the misc folder.

  make compile-all
    - Will build all object files and store them in the obj folder.

  make build
    - Will build all object files, storing them in the obj folder then link them
      creating an executable called project1 in the obj folder. It will also
      create the project1.map file and store it in the source folder and
      generate the dependency file, project1.dep and store it in the misc folder

  make clean
    - Will remove all compiled object, preprocessed output, assembly output,
      executables and build output files.

  make
    - Without any other specifications, make will run make build.
