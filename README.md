# ManoloVagonetaDynamic
manolo vagoneta dinámico, simplemente épico

# DESCRIPTION OF THE MAIN IDEAS
The goal with this algorithm is to provide the elements to be included in a lorry whose total capacity is 15 metric tons (15.000 kg). This has to be done maximizing the total number of kilograms carried in the lorry because each kilogram corresponds to 6€ and we want to get the best out of it. This time, we can not solve this problem by means of a Greedy Algorithm because just sorting the candidates and then deciding if they are included is not sufficient. For example, if we need to cover 10 kg with items whose weight is 2, 3 and 8 kg, with a Greedy algorithm we would include 2 and 3, having 5 kg of wasted space in the end. However, by means of a Dynamical Programming algorithm we can achieve the best solution (in this case, 2 and 8 kg, leaving no empty space).

# FORMAL DESCRIPTION OF THE ALGORITHM
M(i,j) = Maximum weight from a set "i" in a lorry with capacity "j"
M(i,j) = 0 when i == 0
M(i,j) = M(i-1,j) when weight(i*) > j
M(i,j) = max(i-1,j) = max{M(i-1,j), (M(1-1,j - weight(i*)) + weight(i*))} otherwise
