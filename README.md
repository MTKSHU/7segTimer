# 7segTimer
A simple application for Arduino or MSP430 (via Energia) to drive four 7-segment displays through standard 8bit shift registers in a timer-like fashion. This is intended for testing the use of 74HC595s mostly.

---

This code is very heavily based on lucidtronix's tutorial on using 74HC595 shift registers with an Arduino, found here: http://www.lucidtronix.com/tutorials/40. 

---

This was created to run on an MSP430 series MCU  (be it a G2231 or a F5529) and be built by Energia. Due to it's simple nature it should run on anything that the Arduino or Energia software can program. Additionally it could be used as a learning tool for daisy-chaining shift registers.

## Usage
This code is intended to be used to drive four seven-segment displays in a manner similar to that of a 24hr clock. It can be used with any standard style shift register like a 595, 594, or MAX335. Shift registers that can not be cascaded (e.g. are lacking DIN and DOUT) must be connected and addressed individually and will not work with this code without significant modification. If daisy chaining is desired, chips with this functionality should be used. 

The 8th pin of each shift register will not be used, and can be pulled to ground or left floating. Otherwise, connect it as the data sheet specifies. Only three pins from the MCU are required - data, clock, and latch. In my configuration I use the shift registers to drive darlington pair ICs (ULQ2004AN) which are then driving 7 segment numitron tubes. The darlington pairs are used to provide high current, as numitron tubes can pull as much as 150mA when all elements are lit. High current shift registers do exist and can be used here in a more direct fashion.

## Licensing

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at


http://www.apache.org/licenses/LICENSE-2.0


Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


A copy of the license is available in the repository.