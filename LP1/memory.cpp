#include <iostream>
#include <vector>
using namespace std;

class MemoryAllocator {
    vector<int> blocks; // memory blocks
    int last_allocated = 0; // for Next Fit

public:
    MemoryAllocator(vector<int> b) {
        blocks = b;
    }

    void reset(vector<int> b) {
        blocks = b;
        last_allocated = 0;
    }

    void firstFit(vector<int> processes) {
        cout << "\nFirst Fit Allocation:\n";
        vector<int> allocation(processes.size(), -1);

        for (int i = 0; i < processes.size(); i++) {
            for (int j = 0; j < blocks.size(); j++) {
                if (blocks[j] >= processes[i]) {
                    allocation[i] = j;
                    blocks[j] -= processes[i];
                    break;
                }
            }
        }
        display(processes, allocation);
    }

    void bestFit(vector<int> processes) {
        cout << "\nBest Fit Allocation:\n";
        vector<int> allocation(processes.size(), -1);

        for (int i = 0; i < processes.size(); i++) {
            int bestIdx = -1;
            for (int j = 0; j < blocks.size(); j++) {
                if (blocks[j] >= processes[i]) {
                    if (bestIdx == -1 || blocks[j] < blocks[bestIdx])
                        bestIdx = j;
                }
            }
            if (bestIdx != -1) {
                allocation[i] = bestIdx;
                blocks[bestIdx] -= processes[i];
            }
        }
        display(processes, allocation);
    }

    void worstFit(vector<int> processes) {
        cout << "\nWorst Fit Allocation:\n";
        vector<int> allocation(processes.size(), -1);

        for (int i = 0; i < processes.size(); i++) {
            int worstIdx = -1;
            for (int j = 0; j < blocks.size(); j++) {
                if (blocks[j] >= processes[i]) {
                    if (worstIdx == -1 || blocks[j] > blocks[worstIdx])
                        worstIdx = j;
                }
            }
            if (worstIdx != -1) {
                allocation[i] = worstIdx;
                blocks[worstIdx] -= processes[i];
            }
        }
        display(processes, allocation);
    }

    void nextFit(vector<int> processes) {
        cout << "\nNext Fit Allocation:\n";
        vector<int> allocation(processes.size(), -1);
        int j = last_allocated;

        for (int i = 0; i < processes.size(); i++) {
            int count = 0;
            while (count < blocks.size()) {
                if (blocks[j] >= processes[i]) {
                    allocation[i] = j;
                    blocks[j] -= processes[i];
                    last_allocated = j;
                    break;
                }
                j = (j + 1) % blocks.size();
                count++;
            }
        }
        display(processes, allocation);
    }

private:
    void display(vector<int>& processes, vector<int>& allocation) {
        cout << "Process No.\tProcess Size\tBlock No.\n";
        for (int i = 0; i < processes.size(); i++) {
            cout << i + 1 << "\t\t" << processes[i] << "\t\t";
            if (allocation[i] != -1)
                cout << allocation[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }
};

int main() {
    vector<int> blocks = {100, 500, 200, 300, 600};
    vector<int> processes = {212, 417, 112, 426};

    MemoryAllocator allocator(blocks);

    allocator.firstFit(processes);
    allocator.reset(blocks);

    allocator.bestFit(processes);
    allocator.reset(blocks);

    allocator.worstFit(processes);
    allocator.reset(blocks);

    allocator.nextFit(processes);

    return 0;
}
