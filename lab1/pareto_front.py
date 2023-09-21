import matplotlib.pyplot as plt

# criterion1 = [2, 5, 3, 6, 1, 0, 6, 4, 4, 1, 0, 3, 9, 7, 5, 1, 8, 6, 9, 1]
# criterion2 = [7, 0, 6, 0, 8, 5, 3, 9, 4, 1, 5, 4, 1, 5, 5, 4, 9, 8, 3, 8]

# criterion1 = [0, 8, 2, 8, 1, 3, 9, 7, 2, 9, 8, 5, 4, 7, 1, 1, 7, 7, 6, 7]
# criterion2 = [5, 2, 2, 2, 7, 0, 3, 4, 6, 3, 6, 3, 3, 4, 4, 3, 9, 7, 2, 5]

criterion1 = [8, 1, 1, 3, 9, 1, 4, 3, 3, 9, 5, 4, 7, 2, 2, 9, 1, 1, 1, 3]
criterion2 = [8, 9, 0, 2, 4, 7, 6, 5, 7, 1, 3, 3, 3, 8, 5, 1, 0, 8, 7, 6]

plt.scatter(criterion1, criterion2, color='green')

pareto_front = []
for i in range(len(criterion1)):
    is_pareto = True
    for j in range(len(criterion1)):
        if i != j and (criterion1[j] >= criterion1[i] and criterion2[j] >= criterion2[i]):
            is_pareto = False
            break
    if is_pareto:
        pareto_front.append((criterion1[i], criterion2[i]))

pareto_front.sort(key=lambda point: (point[0], -point[1]))
pareto_x, pareto_y = zip(*pareto_front)
plt.plot(pareto_x, pareto_y, color='yellow', linestyle='--')

plt.xlabel('Критерій 1')
plt.ylabel('Критерій 2')
plt.legend()
plt.title('Границя Парето')
plt.grid(True)

plt.show()