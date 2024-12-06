#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Teacher {
    int id;
    set<int> preferenceList;
    int load;

    Teacher(int id, set<int> preferenceList) : id(id), preferenceList(preferenceList), load(0) {}
};

struct Course {
    int id;
    int assignedTeacher;
    Course(int id) : id(id), assignedTeacher(-1) {}
};

bool conflictsWithAssignedCourses(const Course& course, const vector<set<int>>& conflicts, const vector<Teacher>& teachers) {
    for (int teacherId : course.preferenceList) {
        if (teachers[teacherId].load > 0) {
            for (int assignedCourse : teachers[teacherId].preferenceList) {
                if (conflicts[course.id][assignedCourse]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool assignCourses(vector<Teacher>& teachers, vector<Course>& courses, const vector<set<int>>& conflicts) {
    for (int i = 0; i < courses.size(); ++i) {
        if (courses[i].assignedTeacher == -1) {
            for (int j : courses[i].preferenceList) {
                if (teachers[j].load == 0) {
                    teachers[j].load++;
                    courses[i].assignedTeacher = j;
                    if (assignCourses(teachers, courses, conflicts)) {
                        return true;
                    }
                    teachers[j].load--;
                    courses[i].assignedTeacher = -1;
                } else if (!conflictsWithAssignedCourses(courses[i], conflicts, teachers)) {
                    teachers[j].load++;
                    courses[i].assignedTeacher = j;
                    if (assignCourses(teachers, courses, conflicts)) {
                        return true;
                    }
                    teachers[j].load--;
                    courses[i].assignedTeacher = -1;
                }
            }
            return false;
        }
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m, n;
    cin >> m >> n;

    vector<Teacher> teachers;
    vector<Course> courses;
    vector<set<int>> conflicts(n, set<int>());

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        set<int> preferenceList;
        for (int j = 0; j < k; j++) {
            int course;
            cin >> course;
            preferenceList.insert(course - 1); // Course IDs are 1-based, convert to 0-based
        }
        teachers.push_back(Teacher(i, preferenceList));
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int course1, course2;
        cin >> course1 >> course2;
        conflicts[course1 - 1].insert(course2 - 1); // Convert to 0-based indexing
        conflicts[course2 - 1].insert(course1 - 1); // Convert to 0-based indexing
    }

    for (int i = 0; i < n; i++) {
        courses.push_back(Course(i));
        courses[i].preferenceList = teachers[i].preferenceList;
    }

    if (assignCourses(teachers, courses, conflicts)) {
        int maxLoad = 0;
        for (const Teacher& teacher : teachers) {
            maxLoad = max(maxLoad, teacher.load);
        }
        cout << maxLoad << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
