#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

struct Segment {
  int start, end;
};

/**
 * Debugging function which prints a vector's elements.
 *
 * @param v
 *   The vector to print.
 */
void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << '\n';
}

/**
 * Debugging function which prints all the remaining segments.
 *
 * @param segments
 *   The vector of Segments.
 */
void print_segments(vector<Segment> segments) {
  for (int i = 0; i < segments.size(); i++) {
    cout << segments[i].start << ", " << segments[i].end << endl;
  }
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  while (segments.size() > 0) {
    Segment min_seg;
    min_seg.end = 1000000000;

    // Find the leftmost segment.
    int min_seg_idx = 0;
    for (int i = 0; i < segments.size(); i++) {
      if (segments[i].end < min_seg.end) {
        min_seg = segments[i];
        min_seg_idx = i;
      }
    }

    // Use it's end as a point
    points.push_back(min_seg.end);

    // Remove all segments touching this point.
    for (int i = 0; i < segments.size(); i++) {
      Segment seg = segments[i];
      if (seg.start <= points[points.size() - 1] && seg.end >= points[points.size() - 1]) {
        segments.erase(segments.begin() + i);
        // Decrement the iterator as we've removed an item.
        i--;
      }
    }
  }

  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    cout << points[i] << " ";
  }
}
