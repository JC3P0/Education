// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/01/And.tst

load Mystery.hdl,
output-file Mystery.out,
compare-to Mystery.cmp,
output-list a%B3.1.3 b%B3.1.3 c%B3.1.3 d%B3.1.3 out%B3.1.3;

set a 0,
set b 0,
set c 0,
set d 0,
eval,
output;

set a 0,
set b 0,
set c 0,
set d 1,
eval,
output;

set a 0,
set b 0,
set c 1,
set d 0,
eval,
output;

set a 0,
set b 0,
set c 1,
set d 1,
eval,
output;

set a 0,
set b 1,
set c 0,
set d 0,
eval,
output;

set a 0,
set b 1,
set c 0,
set d 1,
eval,
output;

set a 0,
set b 1,
set c 1,
set d 0,
eval,
output;

set a 0,
set b 1,
set c 1,
set d 1,
eval,
output;

set a 1,
set b 0,
set c 0,
set d 0,
eval,
output;

set a 1,
set b 0,
set c 0,
set d 1,
eval,
output;

set a 1,
set b 0,
set c 1,
set d 0,
eval,
output;

set a 1,
set b 0,
set c 1,
set d 1,
eval,
output;

set a 1,
set b 1,
set c 0,
set d 0,
eval,
output;

set a 1,
set b 1,
set c 0,
set d 1,
eval,
output;

set a 1,
set b 1,
set c 1,
set d 0,
eval,
output;

set a 1,
set b 1,
set c 1,
set d 1,
eval,
output;