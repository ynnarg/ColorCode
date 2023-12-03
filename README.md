# ColorCode
ColorCode takes a BitMap (.BMP) file and executes it as code in a state-machine.

## Current Instructions
('green' indicates the register at green)
('%green' indicates a literal contained as green)
- 0 "noOperation" does nothing.
- 1 "mov green blue" moves the value inside the register at blue into the register at green
- 2 "movLiteral green %blue" moves the value blue into the register at green
- 3 "add green blue" adds values inside of both registers together and puts resultant into register 1
- 4 "sub green blue" takes away value of register blue away from register green and puts resultant into register 1
- 5 "mul green blue" multiplies values inside of both registers together and puts resultant into register 1
- 6 "div green blue" divides register green by register blue and puts resultant into register 1 and remainder into register 2
- 7 "print green" prints the char value inside of register green with no newline

# Questions & Answers
## What are the applications?
Absolutely nothing! It's just for fun. See what great images you can make while creating beautiful code.

## Any similar languages?
Yes! Many esoteric languages, especially BrainF**k, heavily resemble ColorCode.

## Planned updates?
Yes and no. It's a hobby, so nothing here is planned. However, I'd love to add rendering support, key inputs, and waiting as well as many more functions to really make this as fun as possible.

## How do I use it? (WINDOWS)
Compile 'main.cpp', optimally using a modern C++ compiler ('c++ main.cpp -o "ColorCode.exe"').
Execute ColorCode.exe, put in the name of '.BMP' file you wish to run. There is an example 'HelloWorld.bmp' file already in the repo, if you wanted to run that you'd enter in 'HelloWorld.bmp' (no quotes).
Enjoy the execution!

## Who is it by?
At the moment, a hobbyist C++ programmer who knows very little.

# Credits
- Arash Partow for the Platform Independent Bitmap Image Reader Writer Library
