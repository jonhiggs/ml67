# Readline/Emacs Layer

This has taken more inspiration from Readline but for things that are not covered, I reached for the default Emacs shortcuts.

There is a readline mode. Documented here are the supported shortcuts from the [readline man pages](http://www.delorie.com/gnu/docs/readline/rlman_13.html).


| Name                | Binding | Description                                                                                       | Supported |
|---------------------|---------|---------------------------------------------------------------------------------------------------|-----------|
| beginning-of-line   | C-a     | Move to the start of the current line.                                                            | •         |
| end-of-line         | C-e     | Move to the end of the line.                                                                      | •         |
| forward-char        | C-f     | Move forward a character.                                                                         | •         |
| backward-char       | C-b     | Move back a character.                                                                            | •         |
| forward-word        | M-f     | Move forward to the end of the next word. Words are composed of letters and digits.               | •         |
| backward-word       | M-b     | Move back to the start of the current or previous word. Words are composed of letters and digits. | •         |
| clear-screen        | C-l     | Clear the screen and redraw the current line, leaving the current line at the top of the screen.  | ☐         |
| redraw-current-line |         | Refresh the current line. By default, this is unbound.                                            | ☐         |
| delete-char         | C-d     | Delete the character at point.                                                                    | •         |
| backward-delete-char| C-h     | Delete the character behind the cursor.                                                           | •         |
| forward-backward-delete-char| | Delete the character under the cursor.                                                            |           |
| quoted-insert       | C-q     | Add the next character typed to the line verbatim.                                                | ☐         |
| tab-insert          | M-TAB   | Insert a tab character.                                                                           | ☐         |
| transpose-chars     | C-t     | Drag the character before the cursor forward over the character at the cursor, moving the cursor forward as well. | ◆ |
| transpose-words     | M-t     | Drag the word before point past the word after point, moving point past that word as well.        |           |
| upcase-word         | M-u     | Uppercase the current or following word.                                                          | ²         |
| downcase-word       | M-l     | Lowercase the current or following word.                                                          | ³         |
| capitalize-word     | M-c     | Capitalize the current or following word.                                                         | ⁴         |
| overwrite-mode      |         | Toggle overwrite mode.                                                                            |           |
| kill-line           | C-k     | Kill the text from point to the end of the line.                                                  | •         |
| backward-kill-line  | C-x Rubout | Kill backward to the beginning of the line.                                                    | •         |
| unix-line-discard   | C-u     | Kill backward from the cursor to the beginning of the current line.                               | •         |
| kill-whole-line     |         |  Kill all characters on the current line, no matter where point is. By default, this is unbound.  |           |

| kill-word           | M-d     | Kill from point to the end of the current word.                                                   | •         |
| backward-kill-word  | M-DEL   | Kill the word behind point. Hyphens are equivalent to a space.                                    | •         |
| unix-word-rubout    | C-w     | Kill the word behind point.                                                                       | ¹         |
| delete-horizontal-space |     | Delete all spaces and tabs around point.                                                          |           |
| kill-region         |         | Kill the text in the current region. By default, this command is unbound.                         |           |
| copy-region-as-kill |         | Copy the text in the region to the kill buffer, so it can be yanked right away.                   |           |
| copy-backward-word  |         | Copy the word before point to the kill buffer. The word boundaries are the same as backward-word. |           |
| copy-forward-word   |         | Copy the word following point to the kill buffer. The word boundaries are the same as forward-word.|          |

| yank                | C-y     | Yank the top of the kill ring into the buffer at point.                                           | •         |
| yank-pop            | M-y     | Rotate the kill-ring, and yank the new top. You can only do this if the prior command is yank or yank-pop.                  | |

• Supported by ML67  
◆ Supported by OSX  
☐ Not Relevant  
¹ I cannot work out how to get to the start of word. Hyphenated words do not go to the beginning. `backward-kill-word` is mapped to ctrl-w as well.  
² You must configure your OS X shortcut for menu option `Make Upper Case` for `All Applications` to ⌥⇧⌘U.  
³ You must configure your OS X shortcut for menu option `Make Lower Case` for `All Applications` to ⌥⌘U.  
⁴ You must configure your OS X shortcut for menu option `Capitalize` for `All Applications` to ⌥⇧⌘C.  

