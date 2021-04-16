# Detailed design
## 2.1 - Detailed list of Linux modules that will be modified/affected

The bash shell will be comified.

- `alias`:`alias.c`, `alias.h`, and `alias.def` from the bash source code will be modified to edit `.bash_aliases`.
- `~/.bash_aliases` will be editted or created. For example, for user `igreen1` `/home/igreen1/.bash_aliases` will be changed to include the new alias permanently. This is not a Linux module, but its important to note its modification. 


## 2.2 Detailed list of any new modules that you will produce [or 'Not Applicable' if there are none]

Not applicable


## 2.3 Class diagram showing affected modules [and any new modules] and how they related to one another

![Change Diagram](https://user-images.githubusercontent.com/40191185/111725996-4a7ff780-8825-11eb-8a53-3172ba2d1596.png)


## 2.4 List or table of explanations of all command line options that will be implemented
| Command Line Options     | Explanation |
|--------------------------|------------------------------------------------------------------------------------|
| `alias [shortcut]="[full command]"`    | Create a temporary alias that will last for the duration of the current bash process |
| `alias -perm [shortcut]="[full command]"`       | Create an alias that will affect both the current bash process and affect all future bash processes|
