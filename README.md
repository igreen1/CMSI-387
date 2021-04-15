# CMSI-387
Ian Green; Bitao Jin; Jacob Longo
Work for CMSI-387: Operating Systems class.

## Using our project
Implementing our project is extremely easy! Either download your favourite [bash version](https://ftp.gnu.org/gnu/bash/) and replace `alias.c`, `alias.h`, and `alias.def` with our modified code, or download our `modified_bash.7z`. Then run `./configure [params]`, `make`, then `make install`. Note: the parameters for configure are generally optional. For more details, see [the documentation](https://www.gnu.org/software/bash/manual/html_node/Installing-Bash.html). Everything is the same from the documentation as we did not touch the Makefile.

To test out our code without messing with your own bash, you can configure with a path parameter: `./configure --prefix=PATH_TO_INSTALL_LOC`. Then, `make` and `make install` like usual. This will install an executable `bash` at `PATH_TO_INSTALL_LOC/bin`. Simply `cd` to the directory and run `./bash` to change to our bash project! 

We recommend running our bash separately from your system default terminal as attempting to affect bash while running it produces unexpected results. Therefore, you will need to build a separate bash, run the make from the separate bash as root, then open your system default terminal to view the changes. In general, this process is less safe.
