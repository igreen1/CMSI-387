# Final Project notes 

## Code changes

### alias.h

The functions save_alias(char* name, char* value) and unsave_alias(char* name) were added for our new functionality. These names were chosen because they follow the alias-unalias naming scheme and reflect the 'saving' of the aliases

`save_alias` adds an alias of format `name=value` to the `.bash_aliases` file.

`unsave_alias` removes an alias of `name` from the `.bash_aliases` file

### alias.c

The functions save_alias(char* name,char* value) and unsave_alias(char* name) were added. These functions are algorithmically straightforward. 

`save_aliases` takes the `.bash_aliases` file and copies it to `.temp_aliases` (a file of the same filename length was purposefully chosen). If in its copy, it encounters an alias of the same `name` as the new alias, it simply does not copy this alias over. Then, the new alias is always appended to the end of the `.temp_aliases` file. `.bash_aliases` is deleted and `.temp_aliases` is renamed as `.bash_aliases`. 

This flow of operations ensures that program interruption does not result in permanent data loss and simplifies program execution.

`unsave_aliases` is the exact same algorithm, except it does not append the alias to the end. So, it will copy `.bash_aliases` to `.temp_aliases`, skipping aliases with the same `name` as the parameter `name`. Then, it deletes `.bash_aliases` and renames `.temp_aliases` to `.bash_aliases`. 

### alias.def

`alias.def` 'defines' the builtin functions in bash terms, calling the appropriate functions from the bash builtin library. The primary edit was adding `save_alias()` after `add_alias()` in the `alias` command definition and adding `unsave_alias()` before `remove_alias()` in the `unalias` command. The `unsave_alias` call preceeded `remove_alias` as remove alias performs a variety of `free` calls that would require additional saving of the data otherwise. The `save_alias` order of execution with regards to `add_alias` is unimportant.

Moreover, the `sflag` variable was added. `sflag` is `0` by default and is set to `1` if `internal_getopt` finds an s option from the command line call. Then, both `save_alias` and `unsave_alias` operations are enclosed in conditionals to execute `if(sflag)`. 

## Kernel Compilation (not part of our project)

### Initial Kernel Compile

@igreen1 's machine was used for compilation as their laptop is relatively powerful and has a large amount of space for the kernal compilation. 12 cores and 14GB of ram were dedicated to the first compile. This compile followed the instructions found on [@bjohnson05 website](https://bjohnson.lmu.build/cmsi387web/osproject.html). It was successful with no edits to the standard compilation path (rare so many thanks to luck on that one)

This compile was clocked at approx. 3 hours. It started at 11:45pm and was finished by 3:00am. It may have finished sooner, however. @igreen1 did not time this and only coincidentally woke up.

### Second Kernel Compile

@igreen1 once again attempted a compile 'for funsies' using the instructions from group 04. This information is available in our `docs` folder for future reference. This compilation was once again successful. It was not timed; however, it took place in less than 6 hours between 12:00am and 6:00am.

## Bash Compilation (part of our project)

### Initial foray 

-After much research, our group found that the [bash source](https://ftp.gnu.org/gnu/bash/) was necessary for our project. This was downloaded.

- Clearly, our first step was a basic installation. This followed the [bash instructions](https://www.gnu.org/software/bash/manual/html_node/Installing-Bash.html). It was successful.

- We added many printf calls to see if bash would print. The files were compiled as they threw errors if syntax errors were present, but the commands did not print.
- The make/make install was repeated a few times, and on the 4th try it worked (weird!)
- We investigated the `alias` and `hash` data structures to determine data flows in the command. 
- After continuing to face issues with compilation, we moved to compiling bash to a different location, rather than trying to replace the bash running in 'terminal' (this is better practice anyways)
- After being able to test our changes, we moved to seperation of concerns for our programming

### Algorithm development 
Working without the bash terminal, we developed our `save_aliases` and `unsave_aliases` functions by passing in custom strings.

- We made a file `file_testing` to test our file manipulation algorithms.
- We researched file manipulation in C and finalized an algorithm. 
- Our algorithm only worked if the replacement was the same size as the current file, this is not teneable as it would require new `aliases` to be the same size as the old, disallowing for example `alias hello='echo "hello"'` to replace `alias hello='echo "hello there"'`. This was unacceptable
- We moved to a more memory intensive algorithm by loading the file and manipulation. However, this ran into similar issues as the original file still had to manipulated. This algorithm was quickly abandoned.
- We decided to copy line-by-line as the file is necessarily split into a series of lines, with one alias per line. 
- Each line was parsed with sscanf and regex. These lines were written to the copied (temp) file as described in our final design algorith above.
- Once we successfully could copy files, we added a 'filter' that would not copy the alias with the `name` given in the parameter. This, shockingly, worked immediately (once we figured out strcmp).
- We then decided to always filter the `name` out and then add our new alias to the end. This was a simplification of editing in place.
- Again, shockingly, we were able to remove and rename the files with ease (yay)
- We copied this algorithm for `remove_name`, removing the insertion at the end. I
- Our code worked in unit tests separately from `alias` so it was time to add the code to Bash!


### Bash integration

- First, we added the functions and compiled so we could see what headers were missing, then added them.
- Next, we began work on the `.def` file, which was very complicated. We started by making ALL alias commands call `save_alias` and `unsave_alias` by inserting them next to any calls to `add_alias` and `remove_alias`. We decided to add the function calls in the .def instead of in `add_alias` and `remove_alias` as it allowed for `add_alias` and `remove_alias` to not be affected (adding our functions would change their signature by adding new sflag parameters. We wanted minimal impact).
- `save_alias` failed immediately. We figured out that the bash cannot handle `~` paths. So, home directory was found manually using `getenv()` from `stdlib`. 
- `save_alias` now worked.
- `unsave_alias` created seg faults. 
- After many `printf` and immediately subsequent `fflush` calls, the error was found to be whenever `name` was referenced. This led to the conclusion that `name` was being deleted. 
- Armed with this knowledge, the issue was obvious. `delete_alias` was called before `unsave_alias`. `unsave_alias` took as an argument `alias->name`. `alias` was deleted in `delete_alias` though, forcing `unsave_alias` to reference previously freed memory. This had two solutions. Either `strcpy` the information first. Or, the easier solution, we moved `unsave_alias` before `delete_alias`. 
- There is an edge case where the program could crash after the alias is removed from `.bash_aliases` but not `unaliased` yet. But, in this crash, the Bash shell probably crashes too, so the permanent effect is the only one that matters.
- We began edge test casing, and it worked!!!


### Primary issues

Our main issue was 
1. Finding what to edit (finding the bash source code was easy but only after we figured we needed the bash source code)
2. Making was difficult because we couldn't edit the 'Terminal' and had to make a separate 'bash' that was then run within the 'Terminal' bash.
3. Any problems in our bash script could crash our bash. However, there was no way to tell if bash exited because the 'wrapping' program was ... another bash! So, there were many times where it appeared the program started working but in reality we were running the system bash not our custom bash.
4. File editing in C is annoying. Editing 'in-place' feels impossible. However, once we created an algorithm that followed C-philosophy, it was suprisingly easy.