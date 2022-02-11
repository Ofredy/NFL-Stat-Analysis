# NFL-Stat-Analysis
Analyzing NFL data to determine who had the best statistical regular season since 2000.

  1. I am compiling 21 years of NFL statistics for quarterbacks, receivers, and running backs into a csv file to perform statistical analysis
  2. Developed the header and cpp file HashTable to store the data. It is a hash table with chaining.
  3. Inside of the HashTable cpp I wrote the functions mean_score, standard_deviation_score, and z_score to compare the players. The player with the highest z-score is then placed into another hash table and written to a txt file
  4. The txt file with the top players is then plotted using the Python library Matplotlib 
