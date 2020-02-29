set xrange [0:5]
set yrange [-1:1]
set xlabel "x"
set ylabel "x"
plot "010-drawing.dat" using 2:4 with lines title "xsinx-logx"

set terminal pdfcairo color enhanced
set output "010-drawings.pdf"
replot

unset output
unset terminal
