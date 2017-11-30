#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  while (!segments.empty()) {
      // safe move:
      // find leftmost end
      // remove all segments which contain the leftmost right

      int leftmost_end = INT_MAX;
      for (int i = 0; i < segments.size(); ++i) {
          if (segments[i].end < leftmost_end)
              leftmost_end = segments[i].end;
      }

      points.push_back(leftmost_end);

      vector<Segment> t;
      for (int i = 0; i < segments.size(); ++i) {
          if (segments[i].start > leftmost_end || segments[i].end < leftmost_end)
              t.push_back(segments[i]);
      }
      segments = t;
  }

  /*
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  */
  return points;
}

void test()
{
    /*
    vector<Segment> segments = {
        {1, 3},
        {2, 5},
        {3, 6}
    };

    vector<Segment> segments = {
        {4,7}, {1,3}, {2,5}, {5,6}
    };
    */

    vector<Segment> segments = {
        {0,1}, {1,2}, {2, 3}
    };

    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
      std::cout << points[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }


    //test();
}
