-Using GCC C/C++ Compiller

-Do not push any .vs/ .vscode/ or output folder (see .gitignore)

-For changes make your own branch and merge when you are done with debugging

-Usefull links:
 -https://medium.com/@prem112/header-files-in-c-e306e685c148 (How header files work)
 -https://www.youtube.com/watch?v=9pjBseGfEPU (How to setup VSCode compiller in linux (may work in windows, but idk))
 -https://www.youtube.com/watch?v=Ar40VjBW3-M (How to setup multiple file compilling in tasks.json)
 -https://stackoverflow.com/questions/63693235/getting-midebuggerpath-error-setting-up-vscode (vscode setup also for windows)


-in the loaded file, root node must be first

-error messages
    - "1" - not eough memory on init


-Commands
--print
---a -> prints entire tree
---c -> prints current node
---fa [path] -> prints entire tree into file
---fc [path] -> prints current node into the file (append)
--del
---c -> delete current node (if does not have children)
---c r -> delete current node and its children
---i [id] -> delete node with specified id (if does not have children), else asks if you want to continue
--checkout [id] -> changes working node to given id
--add [parent] [newId]-> creates new node with given id (if that id does not exist, or if parent has free space)
--load [path] -> load tree from given file
--save -> saves tree into file from which it was loaded
---[path] -> save tree into given file
--clear -> clears the console
--help -> prints out help for the app