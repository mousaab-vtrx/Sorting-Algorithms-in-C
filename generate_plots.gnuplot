#!/usr/bin/env gnuplot

# Sorting Algorithms Performance Comparison - Refactored Design

set datafile separator ","

# PLOT 1: All Algorithms - Linear Scale
set output "stats/sorting_performance.png"
set terminal png size 1200,700 font ",12"
set title "Sorting Algorithm Performance Comparison" font ",14" textcolor rgb "#1a1a1a"
set xlabel "Array Size" font ",12" textcolor rgb "#333333"
set ylabel "Time (milliseconds)" font ",12" textcolor rgb "#333333"
set grid linestyle 1 linecolor rgb "#e0e0e0"
set xtics rotate by 45
set style data linespoint
set key outside right top font ",10"

plot "benchmark_results.csv" every ::1 using 1:2 with linespoint title "Bubble Sort" linewidth 2.5 pointsize 1 linecolor rgb "#E74C3C", \
     "benchmark_results.csv" every ::1 using 1:3 with linespoint title "Selection Sort" linewidth 2.5 pointsize 1 linecolor rgb "#27AE60", \
     "benchmark_results.csv" every ::1 using 1:4 with linespoint title "Insertion Sort" linewidth 2.5 pointsize 1 linecolor rgb "#3498DB", \
     "benchmark_results.csv" every ::1 using 1:5 with linespoint title "Shell Sort" linewidth 2.5 pointsize 1 linecolor rgb "#E67E22", \
     "benchmark_results.csv" every ::1 using 1:6 with linespoint title "Merge Sort" linewidth 2.5 pointsize 1 linecolor rgb "#F39C12", \
     "benchmark_results.csv" every ::1 using 1:7 with linespoint title "Heap Sort" linewidth 2.5 pointsize 1 linecolor rgb "#8E44AD", \
     "benchmark_results.csv" every ::1 using 1:8 with linespoint title "Quick Sort V1" linewidth 2.5 pointsize 1 linecolor rgb "#1ABC9C", \
     "benchmark_results.csv" every ::1 using 1:9 with linespoint title "Quick Sort V2" linewidth 2.5 pointsize 1 linecolor rgb "#C0392B", \
     "benchmark_results.csv" every ::1 using 1:10 with linespoint title "Tim Sort" linewidth 2.5 pointsize 1 linecolor rgb "#d400d4"

# PLOT 2: Efficient Algorithms Only (O(n log n))
set output "stats/sorting_performance_efficient.png"
set terminal png size 1200,700 font ",12"
set title "Efficient Sorting Algorithms Performance (O(n log n))" font ",14" textcolor rgb "#1a1a1a"
set xlabel "Array Size" font ",12" textcolor rgb "#333333"
set ylabel "Time (milliseconds)" font ",12" textcolor rgb "#333333"
set grid linestyle 1 linecolor rgb "#e0e0e0"
set xtics rotate by 45
set style data linespoint
set key outside right top font ",10"
unset logscale

plot "benchmark_results.csv" every ::1 using 1:6 with linespoints title "Merge Sort" linewidth 3 pointsize 1.2 linecolor rgb "#F39C12", \
     "benchmark_results.csv" every ::1 using 1:7 with linespoints title "Heap Sort" linewidth 3 pointsize 1.2 linecolor rgb "#8E44AD", \
     "benchmark_results.csv" every ::1 using 1:8 with linespoints title "Quick Sort V1" linewidth 3 pointsize 1.2 linecolor rgb "#1ABC9C", \
     "benchmark_results.csv" every ::1 using 1:9 with linespoints title "Quick Sort V2" linewidth 3 pointsize 1.2 linecolor rgb "#C0392B", \
     "benchmark_results.csv" every ::1 using 1:10 with linespoints title "Tim Sort" linewidth 3 pointsize 1.2 linecolor rgb "#d400d4"

# PLOT 3: Quadratic Algorithms Only (O(n²))
set output "stats/sorting_performance_quadratic.png"
set terminal png size 1200,700 font ",12"
set title "Quadratic Time Sorting Algorithms (O(n²))" font ",14" textcolor rgb "#1a1a1a"
set xlabel "Array Size" font ",12" textcolor rgb "#333333"
set ylabel "Time (milliseconds)" font ",12" textcolor rgb "#333333"
set grid linestyle 1 linecolor rgb "#e0e0e0"
set xtics rotate by 45
set style data linespoint
set key outside right top font ",10"

plot "benchmark_results.csv" every ::1 using 1:2 with linespoint title "Bubble Sort" linewidth 3 pointsize 1.2 linecolor rgb "#E74C3C", \
     "benchmark_results.csv" every ::1 using 1:3 with linespoint title "Selection Sort" linewidth 3 pointsize 1.2 linecolor rgb "#27AE60", \
     "benchmark_results.csv" every ::1 using 1:4 with linespoint title "Insertion Sort" linewidth 3 pointsize 1.2 linecolor rgb "#3498DB"

# PLOT 4: Shell Sort Comparison with Quadratic Algorithms
set output "stats/sorting_performance_shell.png"
set terminal png size 1200,700 font ",12"
set title "Shell Sort vs Quadratic Algorithms" font ",14" textcolor rgb "#1a1a1a"
set xlabel "Array Size" font ",12" textcolor rgb "#333333"
set ylabel "Time (milliseconds)" font ",12" textcolor rgb "#333333"
unset logscale
set grid linestyle 1 linecolor rgb "#e0e0e0"
set xtics rotate by 45
set style data linespoint
set key outside right top font ",10"

plot "benchmark_results.csv" every ::1 using 1:2 with linespoint title "Bubble Sort" linewidth 2.5 pointsize 1.2 linecolor rgb "#E74C3C", \
     "benchmark_results.csv" every ::1 using 1:3 with linespoint title "Selection Sort" linewidth 2.5 pointsize 1.2 linecolor rgb "#27AE60", \
     "benchmark_results.csv" every ::1 using 1:4 with linespoint title "Insertion Sort" linewidth 2.5 pointsize 1.2 linecolor rgb "#3498DB", \
     "benchmark_results.csv" every ::1 using 1:5 with linespoint title "Shell Sort" linewidth 3 pointsize 1.2 linecolor rgb "#E67E22"

# PLOT 5: Logarithmic Scale (Quadratic Algorithms + Shell Sort)
set output "stats/sorting_performance_logscale.png"
set terminal png size 1200,700 font ",12"
set title "Quadratic Algorithms + Shell Sort on Logarithmic Scale" font ",14" textcolor rgb "#1a1a1a"
set xlabel "Array Size (log scale)" font ",12" textcolor rgb "#333333"
set ylabel "Time (milliseconds, log scale)" font ",12" textcolor rgb "#333333"
set logscale xy
set grid linestyle 1 linecolor rgb "#e0e0e0"
set xtics rotate by 45
set style data linespoint
set key outside right top font ",10"

plot "benchmark_results.csv" every ::1 using 1:2 with linespoints title "Bubble Sort" linewidth 3 pointsize 1.2 linecolor rgb "#E74C3C", \
     "benchmark_results.csv" every ::1 using 1:3 with linespoints title "Selection Sort" linewidth 3 pointsize 1.2 linecolor rgb "#27AE60", \
     "benchmark_results.csv" every ::1 using 1:4 with linespoints title "Insertion Sort" linewidth 3 pointsize 1.2 linecolor rgb "#3498DB", \
     "benchmark_results.csv" every ::1 using 1:5 with linespoints title "Shell Sort" linewidth 3 pointsize 1.2 linecolor rgb "#E67E22"

# PLOT 6: Bar Chart - Performance at Maximum Size (200,000 elements)
set output "stats/sorting_performance_bar.png"
set terminal png size 1400,800 font ",12"
unset logscale
set title "Algorithm Performance at Maximum Test Size (200,000 elements)" font ",16" textcolor rgb "#1a1a1a"
set xlabel "Sorting Algorithm" font ",13" textcolor rgb "#333333"
set ylabel "Execution Time (milliseconds)" font ",13" textcolor rgb "#333333"
set grid ytics linestyle 1 linecolor rgb "#e0e0e0"
set style fill solid 0.80
set boxwidth 0.6 absolute
set key outside right top font ",11" spacing 1.2
set xrange [0.5:9.5]
set yrange [0:*]
set xtics (1 "Bubble\nSort", 2 "Selection\nSort", 3 "Insertion\nSort", 4 "Shell\nSort", \
           5 "Merge\nSort", 6 "Heap\nSort", 7 "Quick V1", 8 "Quick V2", 9 "Tim\nSort") font ",11"
set ytics font ",11"
set tics out
set format y "%.0f"

plot "benchmark_results.csv" every ::10::10 using (1):2 with boxes fill solid linecolor rgb "#E74C3C" linewidth 1.5 title "Bubble Sort", \
     "benchmark_results.csv" every ::10::10 using (2):3 with boxes fill solid linecolor rgb "#27AE60" linewidth 1.5 title "Selection Sort", \
     "benchmark_results.csv" every ::10::10 using (3):4 with boxes fill solid linecolor rgb "#3498DB" linewidth 1.5 title "Insertion Sort", \
     "benchmark_results.csv" every ::10::10 using (4):5 with boxes fill solid linecolor rgb "#E67E22" linewidth 1.5 title "Shell Sort", \
     "benchmark_results.csv" every ::10::10 using (5):6 with boxes fill solid linecolor rgb "#F39C12" linewidth 1.5 title "Merge Sort", \
     "benchmark_results.csv" every ::10::10 using (6):7 with boxes fill solid linecolor rgb "#8E44AD" linewidth 1.5 title "Heap Sort", \
     "benchmark_results.csv" every ::10::10 using (7):8 with boxes fill solid linecolor rgb "#1ABC9C" linewidth 1.5 title "Quick Sort V1", \
     "benchmark_results.csv" every ::10::10 using (8):9 with boxes fill solid linecolor rgb "#C0392B" linewidth 1.5 title "Quick Sort V2", \
     "benchmark_results.csv" every ::10::10 using (9):10 with boxes fill solid linecolor rgb "#d400d4" linewidth 1.5 title "Tim Sort", \
     "benchmark_results.csv" every ::10::10 using (1):2:(sprintf("%d ms", $2)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle, \
     "benchmark_results.csv" every ::10::10 using (2):3:(sprintf("%d ms", $3)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle, \
     "benchmark_results.csv" every ::10::10 using (3):4:(sprintf("%d ms", $4)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle, \
     "benchmark_results.csv" every ::10::10 using (4):5:(sprintf("%d ms", $5)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle, \
     "benchmark_results.csv" every ::10::10 using (5):6:(sprintf("%d ms", $6)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle, \
     "benchmark_results.csv" every ::10::10 using (6):7:(sprintf("%d ms", $7)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle, \
     "benchmark_results.csv" every ::10::10 using (7):8:(sprintf("%d ms", $8)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle, \
     "benchmark_results.csv" every ::10::10 using (8):9:(sprintf("%d ms", $9)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle, \
     "benchmark_results.csv" every ::10::10 using (9):10:(sprintf("%d ms", $10)) with labels center offset 0,0.7 font ",10" textcolor rgb "#333333" notitle