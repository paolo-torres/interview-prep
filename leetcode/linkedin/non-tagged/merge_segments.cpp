/*
    To improve file transfer speed, a file is split up into different
    portions and sent from multiple servers. Receiver downloads the
    file segments and recombine parts into the single requested file.
    Given a segment class, implement task class for download manager.

    Insert items in sorted vector of segments, so long as another
    element starts before the current one, then keep going.

    Time: O(log n) add, O(n) getFileSize
    Space: O(n)
*/

#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Segment {
    int start;
    int end;
};

class DownloadTask {
public:
    // add a segment into recombined file
    void add(Segment s) {
        file.insert(upper_bound(begin(file), end(file), s, comp()), s);
    }

    // find total length of downloaded segments
    int getFileSize() {
        int result = 0;

        for (auto it = begin(file); it != end(file); it = next(it)) {
            int start = it->start;
            int end = it->end;
            bool hasMoved = false;

            while (it != std::end(file) && end >= it->start) {
                end = max(end, it->end);
                it = next(it);
                hasMoved = true;
            }

            if (hasMoved) {
                it = prev(it);
            }

            result += end - start;
        }

        cout << result << endl;
        return result;
    }
private:
    vector<Segment> file;

    struct comp {
        bool operator()(const Segment& a, const Segment& b) {
            return a.start < b.start;
        }
    };
};

int main() {
    DownloadTask task;
    task.add({1, 5});
    task.add({4, 6});
    // returns 5
    task.getFileSize();
    
    task.add({10, 20});
    task.add({25, 30});
    // returns 20
    task.getFileSize();
    
    task.add({19, 29});
    // returns 25
    task.getFileSize();

    return 0;
}
