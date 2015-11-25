#include "OrderedSet.h"
#include<vector>
#include<iterator>
//Objektum elvű alkalmazások fejesztése gyakorlat 2. beadandó
//Feladat: Rendezett fejelemes aciklikus egyirányú láncolt listaként ábrázolt halmaz egészekre.
//Sándor Balézs - AZA6NL

//Az OSNode struct metódusai
OAF::OrderedSet::OSNode:: OSNode() : next(NULL), prev(NULL), value(0){}
OAF::OrderedSet::OSNode:: OSNode(OSNode* next, OSNode* prev, int value) : next(next), prev(prev), value(value){}


//Az OrderedSet osztály metódusai
//Konstruktorok
	//Üres konstruktor
	OAF::OrderedSet::OrderedSet() : _head(new OSNode()), _size(0)
	{
		_head->next = _head;
		_head->prev = _head;
	}
	//Egy elemű halmaz létrehozása
	OAF::OrderedSet::OrderedSet(int x) : _size(1)
	{
		_head = new OSNode(NULL, NULL, 0);
		OSNode newOSNode(_head, _head, x);
		_head->next = &newOSNode;
		_head->prev = &newOSNode;
	}
	//Halmaz létrehozása tömbből
	OAF::OrderedSet::OrderedSet(int* arr, int n) : _size(n)
	{
		_head = new OSNode();
		for(int i = 0; i<n; ++i)
		{
			insert(arr[i]);
		}
	}
	//Halmaz létrehozása vektorból
	OAF::OrderedSet::OrderedSet(std::vector<int>& vec) : _size(vec.size())
	{
		_head = new OSNode();
		for(int i = 0; i<vec.size(); ++i)
		{
			insert(vec[i]);
		}	
	}
	//Halmaz létrehozása std::set-ből
	OAF::OrderedSet::OrderedSet(std::set<int>& set) : _size(set.size())
	{
		std::set<int>::iterator it;
		for (it = set.begin(); it != set.end(); ++it)
		{
			insert(*it);
		}
	}
	//Másoló konstruktor
	OAF::OrderedSet::OrderedSet(const OrderedSet& set)
	{
		_head = new OSNode();
		for (iterator it = set.begin(); it != set.end(); ++it)
		{
			insert(*it);
		}	
	}

//Alap műveletek	-	Az STD::SET alapján
	//ITERATOR - A kezdőelemre mutató iterátort ad!
	OAF::OrderedSet::iterator OAF::OrderedSet::begin()
	{
		return iterator(_head->next);
	}
	OAF::OrderedSet::const_iterator OAF::OrderedSet::begin() const
	{
		return iterator(_head->next);
	}
	//Minden elemet töröl
	void OAF::OrderedSet::clear()
	{
		for (iterator it = begin(); it != end(); ++it)
		{
			erase(*it);
		}
		_size = 0;
	}
	//Megadja, hogy a halmaz üres-e
	bool OAF::OrderedSet::empty() const
	{
		return _size == 0;;
	}
	//ITERATOR - Az utolsó elemre mutató iterátorral tér vissza
	OAF::OrderedSet::iterator OAF::OrderedSet::end()
	{
		return iterator(_head->prev);
	}
	OAF::OrderedSet::const_iterator OAF::OrderedSet::end() const
	{
		return const_iterator(_head->prev);
	}
	//Egy elemet töröl
	void OAF::OrderedSet::erase(const int& x)
	{
		OSNode* pointer = _head->next;
		while(pointer->next != _head && pointer->value != x)
		{
			pointer = pointer->next;
		}
		if(pointer->value == x)
		{
			pointer->prev->next = pointer->next;
			pointer->next->prev = pointer->prev;
			delete pointer;
		}
		--_size;
	}
	//Megkeres egy elemet és visszaad egy rámutató iterátort
	OAF::OrderedSet::iterator OAF::OrderedSet::find(const int& x) const
	{
		iterator it = begin();
		while (it != end() && *it != x)
		{
			++it;
		}
		if(it == end() && *it != x){it.value = NULL;}
		return it;
	}
	//Egy elem hozzáasdása létező listához
	void OAF::OrderedSet::insert(const int x)
	{
		OSNode* pointer = _head->next;
		while((pointer->next != _head)&&(pointer->value < x))
		{
			pointer = pointer->next;
		}
		if(pointer->next->value != x || pointer->next == _head)
		{
			OSNode* newNode = new OSNode(pointer->next, pointer, x);
			pointer->next = newNode;
			pointer->next->prev = newNode;
		}
		++_size;
	}
	//Megadja, hogy egy szám eleme-e a halmaznak
	bool OAF::OrderedSet::isElement(int x) const
	{
		OAF::OrderedSet::iterator it = find(x);
		return it != NULL;
	}
	//Megadja az elemszámot
	size_t OAF::OrderedSet::size() const
	{
		return _size;
	}

//Kívánt műveletek
	//Két halmaz uniója
	OAF::OrderedSet OAF::OrderedSet::uni(const OrderedSet& set) const
	{
		
	}
	//Két halmaz különbsége
	OAF::OrderedSet OAF::OrderedSet::min(const OrderedSet& set) const
	{
		
	}
	//Két halmaz uniója
	OAF::OrderedSet OAF::OrderedSet::uni(const std::set<int>& set) const
	{
		
	}
	//Két halmaz különbsége
	OAF::OrderedSet OAF::OrderedSet::min(const std::set<int>& set) const
	{
		
	}
//Operátorok
	//Két halmaz uniója +operátorral. Kommutatív
	OAF::OrderedSet OAF::OrderedSet::operator+ (const OrderedSet& set) const
	{
		
	}
	//Két halmaz különbsége -operátorral. Kommutatív
	OAF::OrderedSet OAF::OrderedSet::operator- (const OrderedSet& set) const
	{
		
	}
	OAF::OrderedSet OAF::OrderedSet::operator+ (const std::set<int>& set) const
	{
		
	}
	OAF::OrderedSet OAF::OrderedSet::operator- (const std::set<int>& set) const
	{
		
	}
	OAF::OrderedSet operator+ (std::set<int> const&, const OAF::OrderedSet& set)
	{
		
	}
	OAF::OrderedSet operator- (std::set<int> const&, const OAF::OrderedSet& set)
	{
		
	}
	
	//|insert| művelet a következő formában: SET + 5 vagy 5 + SET
	OAF::OrderedSet OAF::OrderedSet::operator+ (const int x) const
	{
		OrderedSet ret = *this;
		ret.insert(x);
		return ret;
	}
	OAF::OrderedSet operator+ (const int x, const OAF::OrderedSet& set)
	{
		OAF::OrderedSet ret = set;
		ret.insert(x);
		return ret;
	}
	//|erase| művelet a következő formában: SET - 5 vagy 5 - SET
	OAF::OrderedSet OAF::OrderedSet::operator- (const int x) const
	{
		OrderedSet ret = *this;
		ret.erase(x);
		return ret;
	}
	OAF::OrderedSet operator- (const int x, const OAF::OrderedSet& set)
	{
		OAF::OrderedSet ret = set;
		ret.erase(x);
		return ret;
	}
	//|insert| művelet a következő formában: SET += 5
	OAF::OrderedSet& OAF::OrderedSet::operator+= (const int x)
	{
		insert(x);
		return *this;
	}
	//|erase| művelet a következő formában: SET -= 5
	OAF::OrderedSet& OAF::OrderedSet::operator-= (const int x)
	{
		erase(x);
		return *this;
	}
			
	//A rendezett halmaz tartalmának átültetése ostream-be
	std::ostream& operator<< (std::ostream& str, const OAF::OrderedSet& set)
	{
		
	}
	//A rendezett halmaz beolvasása egyben  ostream-ből
	std::istream& operator>> (std::istream& str, OAF::OrderedSet& set)
	{
		
	}
	
	//Értékadó operátor
	OAF::OrderedSet& OAF::OrderedSet::operator=(const OrderedSet& set)
	{
		_size = set.size();
		_head = set._head;
	}
	
	//Két halmaz összehasonlítása
	bool OAF::OrderedSet::operator!=(OrderedSet const&)
	{
		
	}
	bool OAF::OrderedSet::operator==(OrderedSet const&)
	{
		
	}
	//OrderedSet és std::set összehasonlítása
	bool OAF::OrderedSet::operator!=(std::set<int> const&)
	{
		
	}
	bool OAF::OrderedSet::operator==(std::set<int> const&)
	{
		
	}
	bool operator!=(std::set<int> const&, OAF::OrderedSet const&)
	{
		
	}
	bool operator==(std::set<int> const&, OAF::OrderedSet const&){
		
	}
	
	//Destruktor
	OAF::OrderedSet::~OrderedSet()
	{
		OSNode* pointer = _head;
		while(pointer->next != _head)
		{
			delete pointer;
		}
		delete _head;
	}
			
			
//OrderedSetIterator osztály metódusai
	//X a;
	OAF::OrderedSetIterator::OrderedSetIterator(){}
	//X b(a)
	OAF::OrderedSetIterator::OrderedSetIterator(OrderedSet set) : curent(set._head){}
	//X b(a)
	OAF::OrderedSetIterator::OrderedSetIterator(OAF::OrderedSet::OSNode* node) : curent(node){}
	//a == b
	bool OAF::OrderedSetIterator::operator== (OAF::OrderedSet::iterator const& setA)
	{
		return curent == setA.curent;
	}
	bool OAF::OrderedSetIterator::operator!= (OAF::OrderedSet::iterator const& setA)
	{
		return curent != setA.curent;
	}
	//*a
	int& OAF::OrderedSetIterator::operator*() const
	{
		return curent->value;
	}
	//a->m
	int* OAF::OrderedSetIterator::operator->() const
	{
		return &curent->value;
	}
	//++a prefix++
	OAF::OrderedSet::iterator& OAF::OrderedSetIterator::operator++ ()
	{
		curent = curent->next;
	}
	//a++ postfix++	
	OAF::OrderedSet::iterator& OAF::OrderedSetIterator::operator++ (int n)
	{
		for(int i = 0; i < n; ++i)
		{
			curent = curent->next;
		}
	}
	//--a prefix--
	OAF::OrderedSet::iterator& OAF::OrderedSetIterator::operator-- ()
	{
		curent = curent->prev;
	}
	//a-- postfix--
	OAF::OrderedSet::iterator& OAF::OrderedSetIterator::operator-- (int n)
	{
		for(int i = 0; i < n; ++i)
		{
			curent = curent->prev;
		}
	}