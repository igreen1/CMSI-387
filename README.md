# CMSI-387
Ian Green; Bitao Jin; Jacob Longo
Work for CMSI-387: Operating Systems class.

## Installing Our Project
Implementing our project is extremely easy! Either download your favourite [bash version](https://ftp.gnu.org/gnu/bash/) and replace `alias.c`, `alias.h`, and `alias.def` with our modified code, or download our `modified_bash.7z`. Then run `./configure [params]`, `make`, then `make install`. To install, you will need root permissions.

Note: the parameters for configure are generally optional. For more details, see [the documentation](https://www.gnu.org/software/bash/manual/html_node/Installing-Bash.html). Everything is the same from the documentation as we did not touch the Makefile.

To test out our code without messing with your own bash, you can configure with a path parameter: `./configure --prefix=PATH_TO_INSTALL_LOC`. Then, `make` and `make install` like usual. This will install an executable `bash` at `PATH_TO_INSTALL_LOC/bin`. Simply `cd` to the directory and run `./bash` to change to our bash project! 

We recommend running our bash separately from your system default terminal as attempting to affect bash while running it produces unexpected results. 

## Running our project
Anytime you wish to permanently add an alias to your `.bash_aliases`, simply add a `-s` parameter to your `alias` command.
Anytime you wish to permanently remove an alias from your `.bash_aliases`, you simply add a `-s` parameter to your `unalias` command. NOTE: because `unalias` starts by checking if your alias is currently in the `alias_hash`, if you `unalias [command]` then attempt `unalias -s [command]` it will not remove it from `.bash_aliases` as it is not recognized as an alias. You can simply open a new terminal though in this edge case! 

