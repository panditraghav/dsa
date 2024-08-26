if [[ "$1" == "-c" ]]; then
  meson compile -C builddir
  if [[ $? == 0 ]]; then
    ./builddir/dsa
  fi
else
  ./builddir/dsa
fi
