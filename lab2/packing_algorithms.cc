#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using containers_and_complexity = pair<int, int>;

enum class SortingMode {
    None,
    Ascending,
    Descending
};

containers_and_complexity NFA(const vector<int>& weights, SortingMode sorting_mode) {
    vector<int> bins(1, 100);
    int containers = 1;
    int comparisons = 0;

    vector<int> sorted_weights = weights;
    if (sorting_mode == SortingMode::Ascending) {
        sort(sorted_weights.begin(), sorted_weights.end());
    } else if (sorting_mode == SortingMode::Descending) {
        sort(sorted_weights.rbegin(), sorted_weights.rend());
    }

    for (int weight : sorted_weights) {
        bool placed = false;
        for (int& bin : bins) {
            comparisons++;
            if (weight <= bin) {
                bin -= weight;
                placed = true;
                break;
            }
        }
        if (!placed) {
            bins.push_back(100 - weight);
            containers++;
        }
    }

    return make_pair(containers, comparisons);
}

containers_and_complexity FFA(const vector<int>& weights, SortingMode sorting_mode) {
    vector<int> bins(1, 100);
    int containers = 1;
    int comparisons = 0;

    vector<int> sorted_weights = weights;
    if (sorting_mode == SortingMode::Ascending) {
        sort(sorted_weights.begin(), sorted_weights.end());
    } else if (sorting_mode == SortingMode::Descending) {
        sort(sorted_weights.rbegin(), sorted_weights.rend());
    }

    for (int weight : sorted_weights) {
        bool placed = false;
        for (int& bin : bins) {
            comparisons++;
            if (weight <= bin) {
                bin -= weight;
                placed = true;
                break;
            }
        }
        if (!placed) {
            bins.push_back(100 - weight);
            containers++;
        }
    }

    return make_pair(containers, comparisons);
}

containers_and_complexity WFA(const vector<int>& weights, SortingMode sorting_mode) {
    vector<int> bins(1, 100);
    int containers = 1;
    int comparisons = 0;

    vector<int> sorted_weights = weights;
    if (sorting_mode == SortingMode::Ascending) {
        sort(sorted_weights.begin(), sorted_weights.end());
    } else if (sorting_mode == SortingMode::Descending) {
        sort(sorted_weights.rbegin(), sorted_weights.rend());
    }

    for (int weight : sorted_weights) {
        int worst_bin_idx = -1;
        int worst_bin_space = -1;
        for (int i = 0; i < bins.size(); i++) {
            comparisons++;
            if (weight <= bins[i] && (worst_bin_idx == -1 || bins[i] < worst_bin_space)) {
                worst_bin_idx = i;
                worst_bin_space = bins[i];
            }
        }
        if (worst_bin_idx != -1) {
            bins[worst_bin_idx] -= weight;
        } else {
            bins.push_back(100 - weight);
            containers++;
        }
    }

    return make_pair(containers, comparisons);
}

containers_and_complexity BFA(const vector<int>& weights, SortingMode sorting_mode) {
    vector<int> bins(1, 100);
    int containers = 1;
    int comparisons = 0;

    vector<int> sorted_weights = weights;
    if (sorting_mode == SortingMode::Ascending) {
        sort(sorted_weights.begin(), sorted_weights.end());
    } else if (sorting_mode == SortingMode::Descending) {
        sort(sorted_weights.rbegin(), sorted_weights.rend());
    }

    for (int weight : sorted_weights) {
        int best_bin_idx = -1;
        int best_bin_space = 101;
        for (int i = 0; i < bins.size(); i++) {
            comparisons++;
            if (weight <= bins[i] && bins[i] < best_bin_space) {
                best_bin_idx = i;
                best_bin_space = bins[i];
            }
        }
        if (best_bin_idx != -1) {
            bins[best_bin_idx] -= weight;
        } else {
            bins.push_back(100 - weight);
            containers++;
        }
    }

    return make_pair(containers, comparisons);
}

int main() {
    vector<int> weights = {
        27, 50, 36, 60, 18, 5, 63, 49, 44, 11, 5, 34, 91, 75, 55, 14, 89, 68, 93, 18
    };

    vector<int> weights2 = {
        5, 82, 22, 82, 17, 30, 93, 74, 26, 93, 86, 53, 43, 74, 14, 13, 79, 77, 62, 75
    };

    vector<int> weights3 = {
        88, 19, 10, 32, 94, 17, 46, 35, 37, 91, 53, 43, 73, 28, 25, 91, 10, 18, 17, 36
    };

    std::vector<int> combined_weights;
    combined_weights.insert(combined_weights.end(), weights.begin(), weights.end());
    combined_weights.insert(combined_weights.end(), weights2.begin(), weights2.end());
    combined_weights.insert(combined_weights.end(), weights3.begin(), weights3.end());

    SortingMode sort_required = SortingMode::None;

    containers_and_complexity nfa_result = NFA(combined_weights, sort_required);
    cout << "NFA containers: " << nfa_result.first << ", NFA comparisons: " << nfa_result.second << endl;

    containers_and_complexity ffa_result = FFA(combined_weights, sort_required);
    cout << "FFA containers: " << ffa_result.first << ", FFA comparisons: " << ffa_result.second << endl;

    containers_and_complexity wfa_result = WFA(combined_weights, sort_required);
    cout << "WFA containers: " << wfa_result.first << ", WFA comparisons: " << wfa_result.second << endl;

    containers_and_complexity bfa_result = BFA(combined_weights, sort_required);
    cout << "BFA containers: " << bfa_result.first << ", BFA comparisons: " << bfa_result.second << endl;

    return 0;
}
