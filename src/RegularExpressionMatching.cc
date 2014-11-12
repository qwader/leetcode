/**
 * Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

**/

class Solution {
struct pattern {
	string *str;
	bool is_marker;
	const char* begin;
	const char* end;
	bool is_match;
};
struct pat_list{
	pattern p;
	pat_list* prev;
	pat_list* next;
};

pat_list* alloc_list(){
	pat_list * p = (pat_list*)malloc(sizeof(pat_list));
	if(p){
		p->p.str = new string();
		p->p.is_marker = false;
		p->p.begin = NULL;
		p->p.end = NULL;
		p->p.is_match = false;
		p->prev = NULL;
		p->next = NULL;
	}
	else{
	//	cout <<"fatal error with null pointer" << endl;
	}
	return p;
}

pat_list* parse_pattern(const char* p){
	if(!p || !*p) return NULL;
	pat_list pl;
	pl.next = alloc_list();
	pat_list *pc = pl.next;
	pc->prev = &pl;
	while(*p){
		// if *p is *, this is a marker
		if(*p == '*'){
			if(pc->p.str->length() == 0){
				return NULL;
			}
			pc->p.is_marker = true;
			pat_list* tmp = alloc_list();
			tmp->prev = pc;
			pc->next = tmp;
			pc = tmp;
		}
		// else, it is a string
		else {
			pc->p.str->push_back(*p);
		}
		p++;
	};
	return pl.next;
}

const char* pat_list_match(pat_list *p, const char* s, const char* se)
{
	const char *pat = p->p.str->c_str();
	p->p.is_match = false;
	if(se < s) return s;
	p->p.begin = s;
	int fixlen = p->p.str->length();
	if(p->p.is_marker){
		fixlen--;
	}
	//match fix part
	while(fixlen-- > 0 && s != se){
		if(*pat != '.' && *pat != *s){
			return s; // error, not match
		}
		pat++;
		s++;
	};
	if(fixlen >= 0)  return s; // error, s is too short 
	//match marker part
	if(p->p.is_marker){
		if(*pat != '.'){
			while(*s == *pat && s != se){s++;};
		}
		else{
			while(*s && s != se){s++;};
		}
	}
	p->p.is_match = true;
	p->p.end = s;
	return s;
}

public:
	bool isMatch(const char* s, const char* p){
	//	cout << "enter, s:" << s << ", pattern:" << p << endl;
		if(!p && s) return false;
		if(p && !s) return false;
		if(!p && !s) return true;
		int slen = strlen(s);
		int plen = strlen(p);
		if(plen == 0 && slen == 0) return true;
		if(plen == 0) return false;
		if(strcmp(p, ".*") == 0) return true;
		if(strcmp(p, ".") == 0){
			if(slen == 1) return true;
			return false;
		}
		pat_list *pat = parse_pattern(p);
		//cout << "parse pattern done" << endl;
		if(!pat) return false;
		pat_list *tp = pat;
		const char *ts = s;
		const char *tse = s + slen;
		while(tp){
			ts = pat_list_match(tp, ts, tse);
			tse = s + slen;
			if(!tp->p.is_match){
				if(tp == pat) return false;
				while(tp != pat){
					tp = tp->prev;
					tp->p.end--;
					if(tp->p.end < tp->p.begin){
						continue;
					}
					else{
						break;
					}
				};
				ts = tp->p.begin;
				tse = tp->p.end;
				continue;
			}
			tp = tp->next;
		}
		if(*ts) return false;
		return true;
	}
};
