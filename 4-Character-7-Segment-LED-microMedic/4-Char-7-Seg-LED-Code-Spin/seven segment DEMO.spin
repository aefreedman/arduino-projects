{{
*********************************************************************
TITLE:       Super Seven Segment Driver DEMO
DESCRIPTION: Shows off 8 digit full alphanumeric ASCII 7 segment display driver
AUTHOR:      Thomas B. Talbot, MD and Daniel Harris
Date:        July 2012
*********************************************************************

  SEGMENT PINOUTS           
 ┌──────────────┐                                    
 │    AAAAA     │        P7 P6 P5 P4 P3 P2 P1 P0      <--- Propeller Pins (Connect to anode display pins)    
 │  FF     BB   │        │  │  │  │  │  │  │  │                                       
 │  FF     BB   │        │  │  │  │  │  │  │  │                                       
 │  FF     BB   │        │  │  │  │  │  │  │  │                                       
 │    GGGGG     │        A  B  C  D  E  F  G  .                                       
 │  EE     CC   │      ┌─┴──┴──┴──┴──┴──┴──┴──┴──┐                                    
 │  EE     CC   │      │                         │                                    
 │  EE     CC   │      │   8     8     8     8   │    Four Digit Common Cathode 7-Segment Dispaly
 │    DDDDD     │      │     .      .     .     .│                                    
 │            ..│      └───┬─────┬─────┬─────┬───┘                                    
 │            ..│          │     │     │     │                                              
 │              │                                                                   
 └──────────────┘         P15   P14   P13   P12       <--- Propeller Pins (Connect to cathode display pins) 
                       
                   Digit   1     2     3     4

  (Anode) Display Pin    
  ┌───────────────────────
                    
       A               
  11 ────┐
           │
       B   │            
   7 ────┫                            
           │      (Cathode) Display Pin 
       C   │    ───────────────┐        
   4 ────┫                           
           │   
       D   │       Digit 1:    12 
   2 ────┫       Digit 2:    9  
           ┣──    Digit 3:    8  
       E   │       Digit 4:    6  
   1 ────┫      
           │      
       F   │
  10 ────┫
           │                 
       G   │
   5 ────┫
           │
     .(DP) │
   3 ────┘

  
}}

CON
  _clkmode = xtal1 + pll16x                                                     'Standard clock mode * crystal frequency = 80 MHz
  _xinfreq = 5_000_000
        
VAR


OBJ
  segs   :      "seven_segments_of_fun"

PUB firstprocedure | i

  'Start the 7-segment display driver
  segs.start(0,15,12)

  '======================== Begin printing things =========================
  
  delay(50)
  segs.print(string("--------"))
  delay(800)                                  

  segs.sequence(string(" Seven Segments oF Fun "), 3, 6)
  delay(5_000)
  segs.scroll(string("        Propeller 7-SEG driver by thomas talbot         "), 3,1)
  delay(7_500)

  '======================== Count in decimal and hex ======================
  segs.blank
  repeat i from 0 to 255 
    delay(30)
    segs.dec(i)
    segs.hexByte(0,i)                     
  delay(2_500)

  '=========================== Print more stuff ===========================
  segs.blank
  segs.blink(string("BLINK   "),6)

  delay(5_000)
  segs.blank
  delay(1_000)

  segs.sequence(string("TESTover"), 3, 2)                                 


  'All done, loop forever doing nothing
  repeat

  
PRI delay(ms)                                           ' delay in milliseconds
    waitcnt (clkfreq / 1000 *ms + cnt)

  
DAT

{{

┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
│                                                   TERMS OF USE: MIT License                                                  │                                                            
├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
│Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation    │ 
│files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy,    │
│modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software│
│is furnished to do so, subject to the following conditions:                                                                   │
│                                                                                                                              │
│The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.│
│                                                                                                                              │
│THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE          │
│WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR         │
│COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,   │
│ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                         │
└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
}}          