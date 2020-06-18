class Solution
{
	const int MAXN = 10005;
	int parent[10005];
	//vector<int> parent(10005);这么写貌似有问题
	int email_id = 0;
	map<string, int> email2id;
	map<int, string> id2email;
	map<string, string> email2name;
	map<int, string> person_id2name;
	int person_id = 0;

public:
	//email地址是唯一的，email映射为id，id连通的一个分量即对应了一个唯一的用户
	int find_parent(int x)
	{
		if (parent[x] != x)
		{
			int tmp = find_parent(parent[x]);
			parent[x] = tmp;
			return tmp;
		}
		else
			return x;
	}

	void init()
	{
		for (int i = 0; i < MAXN; i++)
		{
			parent[i] = i;
		}
	}

	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
	{
		init();
		for (auto account : accounts)
		{
			string name = account[0];
			for (int i = 1; i < account.size(); i++)
			{	
				email2name[account[i]] = account[0];
				if (email2id.find(account[i]) == email2id.end())
				{
					email2id[account[i]] = email_id;
					id2email[email_id] = account[i];
					email_id++;
				}
				if (i != 1)
				{
					//合并
					int a = email2id[account[1]];
					int b = email2id[account[i]];
					int roota = find_parent(a);
					int rootb = find_parent(b);
					if (roota != rootb)
					{
						parent[roota] = rootb;
					}
				}
			}
		}
		set<int> roots;
		vector<vector<string>> res;
		for (int i = 0; i < email_id; i++)
		{
			roots.insert(find_parent(i));
		}
		map<int, int> rootID2person;
		for (auto root : roots)
		{	
			person_id2name[person_id] = email2name[id2email[root]];
			rootID2person[root] = person_id++;
		}
		map<int, vector<string> > person_id2emails;
		for (int i = 0; i < email_id; i++)
		{
			string email = id2email[i];
			int rootID = find_parent(i);
			person_id2emails[rootID2person[rootID]].push_back(email);
		}
		for (map<int, vector<string>>::iterator it = person_id2emails.begin(); it != person_id2emails.end(); it++)
		{
			vector<string> buf;
			buf.push_back(person_id2name[it->first]);
			for (auto email : it->second)
			{
				buf.push_back(email);
			}
            sort(buf.begin()+1,buf.end());
			res.push_back(buf);
		}
		return res;
	}
};