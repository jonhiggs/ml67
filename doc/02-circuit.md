# Deciphering the Circuit

If you are not interested in how it works, you can safely move on to the next section [Patching in](./patching).

## Disassembly

The first job is to pull apart your keyboard. Remove the screws from the bottom. There will be a couple of tabs at the back. Pop the outside shell out with a small screwdriver, then pop out the front.

Remove the plastic shroud, then lift the keyboard out. It will be connected to a small controller via a 28pin connector. Be gentle and it should lift out.

At this point you should have a circuit board that looks like this.

![Underside of Board](../images/board-underside.png)

Now we are ready to move on to deciphering the circuit.



I'm going to cheat for now and just give you the answer. Perhaps you can reverse-engineer how I came to the answer if you are interested.


![The original 28pin header](../images/header.png)

The first thing we should do is decide upon is what to name each of the keys. It doesn't really matter what they are called at this point, but to make things easier, I'm going to use the same naming scheme we will use later within the TMK firmware.

![Keys](../images/keys.png)

Each key has three values. Top is the TMK identifier which we will use in the firmware [later on](./04-tmk). The Middle value is the column. The last is the row.

TODO: fix link.  
If you don't understand how a keyboard matrix works, I recommend you take a look at [this]().

The factory matrix looks like this:

|    | C0  | C1  | C2  | C3  | C4  | C5  | C6  | C7  | C8  | C9  | C10 | C11 | C12 | C13 | C14 | C15 |
|----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| R0 |     | K11 | K12 | K13 | K14 | K17 | K18 | K19 | K1A | K45 |     |     |     |     |     |     |
| R1 |     | K10 | K20 |     | K15 | K16 | K1C |     | K1B |     | K0E |     |     | K41 |     | K30 |
| R2 |     | K21 | K22 | K23 | K24 | K27 | K28 | K29 | K2A | K43 | K1D |     |     |     |     | K3B |
| R3 |     | K00 |     |     | K25 | K26 |     |     | K2B | K42 |     | K44 |     |     | K3C |     |
| R4 |     | K31 | K32 | K33 | K34 | K37 | K38 | K39 |     |     | K2C |     |     |     |     |     |
| R5 |     |     |     |     | K35 | K36 |     |     | K3A | K46 |     | K49 | K4A | K47 | K48 |     |
| R6 | K40 | K0D |     |     | K05 | K06 | K0C |     | K0B |     | K3D |     |     |     |     |     |
| R7 |     | K01 | K02 | K03 | K04 | K07 | K08 | K09 | K0A |     |     |     |     |     |     |     |


## Merging Columns

Each row and each column will require a pin on your Teensy. It is possible to merge some columns together to reduce the total number of pins required.

Straight away it's pretty obvious that a couple of the columns can be merged together to save us some pins.

I'm going to perform the following merges:

- C12 -> C1
- C14 -> C2
- C0  -> C3
- C13 -> C7

Afterwards, the merged matrix will look like this:

|    | C1  | C2  | C3  | C4  | C5  | C6  | C7  | C8  | C9  | C10 | C11 | C15 |
|----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| R0 | K11 | K12 | K13 | K14 | K17 | K18 | K19 | K1A | K45 |     |     |     |
| R1 | K10 | K20 |     | K15 | K16 | K1C | K41 | K1B |     | K0E |     | K30 |
| R2 | K21 | K22 | K23 | K24 | K27 | K28 | K29 | K2A | K43 | K1D |     | K3B |
| R3 | K00 | K3C |     | K25 | K26 |     |     | K2B | K42 |     | K44 |     |
| R4 | K31 | K32 | K33 | K34 | K37 | K38 | K39 |     |     | K2C |     |     |
| R5 | K4A | K48 |     | K35 | K36 |     | K47 | K3A | K46 |     | K49 |     |
| R6 | K0D |     | K40 | K05 | K06 | K0C |     | K0B |     | K3D |     |     |
| R7 | K01 | K02 | K03 | K04 | K07 | K08 | K09 | K0A |     |     |     |     |




---

http://www.keyboard-layout-editor.com/##@@_c=#3c3c3c&t=#c5c5c5;&=K00%0AR3%0A%0A%0A%0A%0AC1&=K01%0AR7%0A%0A%0A%0A%0AC1&=K02%0AR7%0A%0A%0A%0A%0AC2&=K03%0AR7%0A%0A%0A%0A%0AC3&=K04%0AR7%0A%0A%0A%0A%0AC4&=K05%0AR6%0A%0A%0A%0A%0AC4&=K06%0AR6%0A%0A%0A%0A%0AC5&=K07%0AR7%0A%0A%0A%0A%0AC5&=K08%0AR7%0A%0A%0A%0A%0AC6&=K09%0AR7%0A%0A%0A%0A%0AC7&=K0A%0AR7%0A%0A%0A%0A%0AC8&=K0B%0AR6%0A%0A%0A%0A%0AC8&=K0C%0AR6%0A%0A%0A%0A%0AC6&=K0D%0AR6%0A%0A%0A%0A%0AC1&=K0E%0AR1%0A%0A%0A%0A%0AC10;&@_w:1.5;&=K10%0AR1%0A%0A%0A%0A%0AC1&=K11%0AR0%0A%0A%0A%0A%0AC1&=K12%0AR0%0A%0A%0A%0A%0AC2&=K13%0AR0%0A%0A%0A%0A%0AC3&=K14%0AR0%0A%0A%0A%0A%0AC4&=K15%0AR1%0A%0A%0A%0A%0AC4&=K16%0AR1%0A%0A%0A%0A%0AC5&=K17%0AR0%0A%0A%0A%0A%0AC5&=K18%0AR0%0A%0A%0A%0A%0AC6&=K19%0AR0%0A%0A%0A%0A%0AC7&=K1A%0AR0%0A%0A%0A%0A%0AC8&=K1B%0AR1%0A%0A%0A%0A%0AC8&=K1C%0AR1%0A%0A%0A%0A%0AC6&_w:1.5;&=K1D%0AR2%0A%0A%0A%0A%0AC10;&@_w:1.75;&=K20%0AR1%0A%0A%0A%0A%0AC2&=K21%0AR2%0A%0A%0A%0A%0AC1&=K22%0AR2%0A%0A%0A%0A%0AC2&=K23%0AR2%0A%0A%0A%0A%0AC3&=K24%0AR2%0A%0A%0A%0A%0AC4&=K25%0AR3%0A%0A%0A%0A%0AC4&=K26%0AR3%0A%0A%0A%0A%0AC5&=K27%0AR2%0A%0A%0A%0A%0AC5&=K28%0AR2%0A%0A%0A%0A%0AC6&=K29%0AR2%0A%0A%0A%0A%0AC7&=K2A%0AR2%0A%0A%0A%0A%0AC8&=K2B%0AR3%0A%0A%0A%0A%0AC8&_w:2.25;&=K2C%0AR4%0A%0A%0A%0A%0AC10;&@_w:2;&=K30%0AR1%0A%0A%0A%0A%0AC15&=K31%0AR4%0A%0A%0A%0A%0AC1&=K32%0AR4%0A%0A%0A%0A%0AC2&=K33%0AR4%0A%0A%0A%0A%0AC3&=K34%0AR4%0A%0A%0A%0A%0AC4&=K35%0AR5%0A%0A%0A%0A%0AC4&=K36%0AR5%0A%0A%0A%0A%0AC5&=K37%0AR4%0A%0A%0A%0A%0AC5&=K38%0AR4%0A%0A%0A%0A%0AC6&=K39%0AR4%0A%0A%0A%0A%0AC7&=K3A%0AR5%0A%0A%0A%0A%0AC8&=K3B%0AR2%0A%0A%0A%0A%0AC15&=K3C%0AR3%0A%0A%0A%0A%0AC14&=K3D%0AR6%0A%0A%0A%0A%0AC10;&@_w:1.75;&=K40%0AR6%0A%0A%0A%0A%0AC0&_w:1.25;&=K41%0AR1%0A%0A%0A%0A%0AC13&_w:1.25;&=K42%0AR3%0A%0A%0A%0A%0AC9&_w:1.25;&=K43%0AR2%0A%0A%0A%0A%0AC9&_w:2.75&w2:3;&=K44%0AR3%0A%0A%0A%0A%0AC11&_x:0.25&w:1.25;&=K45%0AR0%0A%0A%0A%0A%0AC9&_w2:1.25;&=K46%0AR5%0A%0A%0A%0A%0AC9&_x:0.25;&=K47%0AR5%0A%0A%0A%0A%0AC13&=K48%0AR5%0A%0A%0A%0A%0AC14&=K49%0AR5%0A%0A%0A%0A%0AC11&=K4A%0AR5%0A%0A%0A%0A%0AC12
