# Keymaps

There are currently two keymaps to choose from; `standard` or `unix`.

To choose which keymap you would like to use, you must set the `KEYMAP` variable in the `Makefile`.


## standard

This is a standard keymap that emulates the keyboard as it comes out of the Filco factory. It exists only for reference as it's a little bit pointless to make a programmable keyboard and then not program it.


## unix

This is a basic Unix keymap. I've made some modifications to the layout which to suit my own tastes. I've moved `command` and `option` to either side of `space`. I've modified the function layer to use more Unixy shortcuts (a combination of emacs/readline/vim/others).

I've also added a `tmux` prefix key (in which to use you need to configure the tmux prefix to `M-,`).

`Shift-Esc` now sends a `~` too. No point in moving `~` all the way across the keyboard when you don't have to.

There is a layer which can be turned on which emulates emacs and it's shortcuts from within OSX. This won't work for any other OS other than OSX but I will probably write more OS compatibility in the future. Probably for Android first, then, maybe Linux.

The Capslock LED now also acts as an indicator for the Emacs layer. NB: this depends on a [pull request](https://github.com/tmk/tmk_keyboard/pull/198) that I've requested to be merged but as of 25/04/2015 hasn't been just yet. For the meantime, you could use my [fork](https://github.com/jonhiggs/tmk_keyboard/tree/layer_led).
