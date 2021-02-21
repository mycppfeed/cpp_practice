# http://sourceware.org/gdb/wiki/FAQ: to disable the
# "---Type <return> to continue, or q <return> to quit---"
# in batch mode:
# set width 0
# set height 0
# set verbose off
set print asm-demangle on
set print demangle on

# at entry point - cmd1
b vtable.cpp:73

echo \n
echo =========================================\n\n
commands 1
  echo MyClass c1   :
  print c1

  echo DerivedX dx1 :
  print dx1

echo \n
echo =========================================\n\n
  echo Parent p1    :
  print p1

  echo Derived d1   :
  print d1

echo \n
echo =========================================\n\n
  echo Mother m1    :
  print m1

  echo Father f1    :
  print f1

  echo Child ch1    :
  print ch1

echo \n
echo =========================================\n\n
  echo Child ch1    :
  x/32gx 0x555555557ca8

echo \n
echo =========================================\n\n
  # continue
end


# # printf line - cmd2
# b test.c:17
# commands 2
#   p i
#   p b
#   continue
# end

# # int b = line - cmd3
# b test.c:16
# commands 3
#   p i
#   p b
#   continue
# end

# # show arguments for program
# show args
# printf "Note, however: in batch mode, arguments will be ignored!\n"
#
# # note: even if arguments are shown;
# # must specify cmdline arg for "run"
# # when running in batch mode! (then they are ignored)
# # below, we specify command line argument "2":
# run 2     # run
#
# #start # alternative to run: runs to main, and stops
# #continue
#
