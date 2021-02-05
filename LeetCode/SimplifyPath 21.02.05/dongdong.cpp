class Solution {
public:
	string simplifyPath(string path) {
		vector<string> totalpath;
		string subpath = "";
		string answer = "";
		path += "/";
		for (int i = 0; i < path.size(); i++) {
			if (i != 0) {
				if (path[i] != '/') {
					subpath += path[i];
				}
				else {
					if (subpath != ".." && subpath != "." && subpath != "") {
						totalpath.push_back(subpath);
					}
					else if (subpath == "..") {
						if (totalpath.size() != 0) {
							totalpath.pop_back();
						}
					}
					subpath = "";
				}
			}
		}

		for (int i = 0; i < totalpath.size(); i++) {
			answer += "/" + totalpath[i];
		}
		if (answer.size() < 1) {
			answer += "/";
		}
		return answer;
	}
};