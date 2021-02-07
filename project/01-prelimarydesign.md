# Preliminary design
## 1.1 - Description of modification/addition to Linux

**Permanent Alias:** 

The `alias` command currently only creates an alias while the bash terminal is open. We would modify this command to affect the user's `.bash_alias` file and add the alias as a permanent feature. To use this feature while maintaining backwards compatibility, we will make it available via the `-perm` option

 Permanently add alias: `alias -perm hello='echo'`

 Temporarily add alias (during lifetime of bash terminal): `alias hello='echo'` 

## 1.2 Rationale as to why this is a good idea, or what the good points of it are

Usually when people use `alias` they want the command to be permanent. It is generally an important shortcut to their workflow. Many first-time Linux users assume the command permanently creates an alias, and this leads to unnecessary confusion. Although these new users will still have to learn the `-perm` command, it will save them the headache of editing `~/.bash_aliases` or the `~/.bashrc` file, which can be more difficult.

For experienced users, this change will help reduce the time necessary to add a permanent alias. It will also eliminate the need to edit the file in the home directory, which is annoying when the terminal is currently viewing another directory. 


## 1.3 Prelimary list of (possible) Linux modules that will be modified/affected

`alias`: This modification will be added to the alias module. Adding `-perm` after the command will now automatically edit the `~/.bash_aliases` file. To allow the alias to be used immediately in the terminal, the normal `alias` will still be used as well as the aliases from the `.bash_aliases` file are only loaded when the terminal opens.

Though not a module, it is worth noting that the ~/.bash_aliases file in the user's home directory will be edited by this command. 

## 1.4 Preliminary list of any new modules that you will produce (or N/A)

N/A
