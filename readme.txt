Just copy the files into your project dir (where bin, build, etc. are also located) and you're ready to go!

--------------------------------
Further Information:
 
Visual Studio 2017:
• File->Open->Folder… and select the project folder
• Right-Click on any file in the Solution Explorer
• In the context menu you will see “make build, make build and run, etc.” 
	o Click on any of it to execute the corresponding task
	o The tasks are editable and extendable, you can have a look at them in “tasks.vs.json” in the “.vs” dir.
• For on-the-fly static analysis use Resharper https://www.jetbrains.com/resharper/ 
	o get your license here: https://www.jetbrains.com/student/


 
Visual Studio Code:
• Make sure, that the C++ extension is installed
• File->Open Folder… and select the project folder
• The standard build task is “make build and run” and can be triggered by the shortcut Ctrl+Shift+B
• The other build tasks are accessible by: 
	1.	Ctrl+Shift+P
	2.	Enter “run task” or use auto-completion and press enter
	3.	Choose a task from the dropdown-list and press enter
• The tasks are also editable and extendable, you can have a look at them in “tasks.json” in the “.vscode” dir.
	o It’s possible to assign shortcuts to the tasks (https://code.visualstudio.com/docs/editor/tasks#_binding-keyboard-shortcuts-to-tasks)
	o Tasks can be parametrized according to the platform (e.g. use a makefile under Linux and a batch-file under windows)
• For on-the-fly static analysis use clang and/or cppcheck together with C/C++ Advanced Lint https://marketplace.visualstudio.com/items?itemName=jbenden.c-cpp-flylint
	o Don't forget to add clang and cppcheck to your PATH variable

If you have any questions feel free to contact me: bitteran@hs-pforzheim.de