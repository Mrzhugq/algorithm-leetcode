#include<set>
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

struct Custom
{
	string str_FirstName;
	string str_LastName;
	long l_ID;
};


//1.第一种版本---------------------------------------------------------------------------
template<typename T>
inline void hash_combine(size_t& seed, const T& val)
{
	seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename T>
inline void hash_val(size_t& seed, const T& val)
{
	hash_combine(seed, val);
}

template<typename T, typename... Types>
inline void hash_val(size_t& seed, const T& val, const Types&... args)
{
	hash_combine(seed, val);
	hash_val(seed, args...);
}

template<typename... Types>
inline size_t hash_val(const Types&... args)
{
	size_t seed = 0;
	hash_val(seed, args...);
	return seed;
}

struct CustomHash //哈希函数 
{
	std::size_t operator()(const Custom& custom) const
	{
		return hash_val(custom.str_FirstName, custom.str_LastName, custom.l_ID);
	}
};

struct CustomEqualTo
{
	bool operator()(const Custom& c1, const Custom& c2) const
	{
		return c1.str_FirstName == c2.str_FirstName &&
			c1.str_LastName == c2.str_LastName &&
			c1.l_ID == c2.l_ID;
	}
};


//2.---------------------------------------------------------------偏特化版本 
/*
namespace std 
{
	template<>
	struct hash<Custom>
	{
		std::size_t operator()(const Custom& custom) const
		{
			return hash_val(custom.str_FirstName, custom.str_LastName, custom.l_ID);
		}
	};

	template<>
	struct equal_to<Custom>
	{
		bool operator()(const Custom& c1, const Custom& c2) const
		{
			return c1.str_FirstName == c2.str_FirstName &&
				c1.str_LastName == c2.str_LastName &&
				c1.l_ID == c2.l_ID;
		}
	};
}

可以这样定义，不用指定哈希函数了 
unordered_set<Custom> hash_set;   
*/


int main()
{
	unordered_set<Custom, CustomHash, CustomEqualTo> hash_set;

	hash_set.insert(Custom{ "san", "Zhang", 1l });
	hash_set.insert(Custom{ "si", "Li", 2l });
	hash_set.insert(Custom{ "er", "Wang", 3l });
	hash_set.insert(Custom{ "wu", "Zhao", 4l });
	hash_set.insert(Custom{ "liu", "Guan", 5l });
	hash_set.insert(Custom{ "qi", "Wu", 6l });
	hash_set.insert(Custom{ "ba", "Wei", 7l });

	cout << "bucket size: " << hash_set.bucket_count() << endl;
	for (int i = 0; i < hash_set.bucket_count(); i++)
	cout << "bucket #" << i << " has " << hash_set.bucket_size(i) << " items." << endl;
}


