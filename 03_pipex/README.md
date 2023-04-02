# This is | pipex
42 project pipex, passed 125/100

## Goal
Discover in detail a UNIX mechanism that we already know by using it in our program.

## Problems you will solve with pipex
Executing C programs "on steroids" leveraging the full reach of the shell and system calls.

## Key Takeaways
Each time you call a system process its execution will overwrite the running process, therefore you'll need to "fork"
i.e. reproduce an exact copy of the memory at a point in time and "sacrifice" it for system execution.
This compels you also to manage input and output with file descriptors accordingly, piping information in logical and timely ways, as well as handle potential erorrs that may arise and forward exit statuses.
In all a great learning experience also this time, so fasten your seat belts and get ready for some hard thinking should you decided to try this kind of project.

## Usage mandatory part

`make`

### Syntax

`./pipex infile "shell cmd with options" "shell cmd with options" outfile`

equates to:

`< infile shell cmd with options | shell command with options > outfile`

## Usage bonus part

`make bonus`

### Syntax
same as mandatory but n pipes allowed

### Syntax heredoc

`./pipex here_doc DELIMITER "shell cmd with options" "shell cmd with options" outfile`

equates to:

`shell cmd with options <<DELIMITER | shell cmd with options >> outfile`

## Credits and thanks to:
The staff at codevault; 42 Heilbronn's fellow students Alessandro, Max, Rouven, Jamshidbek, Hei Yiu, Florian among many other smart brains too many to mention here, in addition to great evaluators and people around the world who built and shared great code, learnings and tests; 42 Heilbronn's staff who make this possible at all | thank You all.
