from collections import Counter

def borda_voting(profile):
    borda_points = Counter()
    for vote, weight in profile:
        for i, candidate in enumerate(vote):
            borda_points[candidate] += weight * (len(vote) - i)
    
    winner = max(borda_points, key=borda_points.get)
    return winner

def copeland_voting(profile):
    copeland_points = Counter()
    for i in range(len(profile)):
        for j in range(i + 1, len(profile)):
            for candidate in profile[i][0]:
                if candidate in profile[j][0]:
                    copeland_points[candidate] += profile[i][1]
                elif candidate not in copeland_points:
                    copeland_points[candidate] = 0
    
    winner = max(copeland_points, key=copeland_points.get)
    return winner

def parallel_elimination_voting(profile):
    eliminated_candidates = set()
    remaining_candidates = set(profile[0][0])
    
    for vote, weight in profile:
        for i, candidate in enumerate(vote):
            if candidate not in eliminated_candidates:
                remaining_candidates.add(candidate)
                break
    
    winner = max(remaining_candidates, key=lambda c: sum(weight for v, weight in profile if c in v))
    return winner

profile = [(['d', 'a', 'c', 'b'], 2),
           (['a', 'b', 'c', 'd'], 6),
           (['b', 'c', 'd', 'a'], 3)]

borda_winner = borda_voting(profile)
copeland_winner = copeland_voting(profile)
parallel_elimination_winner = parallel_elimination_voting(profile)

print("Winner (Borda method):", borda_winner)
print("Winner (Copeland method):", copeland_winner)
print("Winner (Parallel elimination method):", parallel_elimination_winner)