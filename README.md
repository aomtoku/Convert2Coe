Convert2Coe
===========

This program converts PPM to CORE(*.core)

the PPM format is
   - A "Magic Number"  -- P6 or P3
        P6:
	p3:
   - White Space.(0x0a)
   - A Width
   - White Space.(0x20)
   - A Height.
   - White Space.(0x0a)
   - The Maximum Color - Component Value
   - White Space.
   - 

the COE format is 

   - memory_initialization_radix = <value> ;
   - memory_initialization_vector = <value> , <value> , ......... <value>;

This program converts PPM to COE in order to make a memory file on Spartan3AN, Xilinx.
the usage :

$ cd src 
$ make
$ cd ../bin
$ ./convert2coe <*.ppm>.ppm <*>.coe


REFERENCE:
       Jef Poskanzer  http://www.martinreddy.net/gfx/2d/PPM.txt
       http://japan.xilinx.com/support/documentation/sw_manuals/xilinx11/cgn_r_coe_file_syntax.htm


