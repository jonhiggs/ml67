# 04. TMK Firmware

As I mentioned in the Important Notes in [Chapter 2](./02-circuit.md), inside the tmk firmware, we need to flip our understanding of rows and columns. The direction of the diodes on the Filco board will prevent any keys to register. Rather than disassemble the entire thing and turn all the diodes around (and force you all to do the same), I'm going to allow this inconsistency and hope that one day in the future I can fix it in software.

So to reiterate, inside the firmware rows connect to the pins on the Filco beginning with `C` and the columns connect to the pins on the Filco beginning with `R`. From now on, I will clarify which definition I'm meaning by the terms 'firmware row/column' or 'Filco row/column'.

Now with that cleared up, I'll start to go through the firmware.


## Modifying the Code

TODO


## Keymaps

There are currently two keymaps to choose from; `standard` or `unix`.

To choose which keymap you would like to use, you must set the `KEYMAP` variable in the `Makefile`.


### standard

This is a standard keymap that emulates the keyboard as it comes out of the Filco factory. It exists only for reference as it's a little bit pointless to make a programmable keyboard and then not program it.


### unix

This is a basic Unix keymap. I've made some modifications to the layout which to suit my own tastes. I've moved `command` and `option` to either side of `space`. I've modified the function layer to use more Unixy shortcuts (a combination of emacs/readline/vim/others).

I've also added a `tmux` prefix key (in which to use you need to configure the tmux prefix to `M-,`).

`Shift-Esc` now sends a `~` too. No point in moving `~` all the way across the keyboard when you don't have to.

There is a layer which can be turned on which emulates emacs and it's shortcuts from within OSX. This won't work for any other OS other than OSX but I will probably write more OS compatibility in the future. Probably for Android first, then, maybe Linux.

The Capslock LED now also acts as an indicator for the Emacs layer. NB: this depends on a [pull request](https://github.com/tmk/tmk_keyboard/pull/198) that I've requested to be merged but as of 25/04/2015 hasn't been just yet. For the meantime, you could use my [fork](https://github.com/jonhiggs/tmk_keyboard/tree/layer_led).



## Makefile Tasks

`make git_update`  
This will pull and checkout the latest origin/master.

`make git_reset`  
Loose all your local changes and revert to origin/master.




**[Next](./05-leds.md)**

