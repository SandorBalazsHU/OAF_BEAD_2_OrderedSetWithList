#ifndef ORDEREDSET_H_INCLUDED
#define ORDEREDSET_H_INCLUDED
#include<vector>
#include<set>
#include<iterator>
//Objektum elvű alkalmazások fejesztése gyakorlat 2. beadandó
//Feladat: Rendezett fejelemes aciklikus egyirányú láncolt listaként ábrázolt halmaz egészekre.
//Sándor Balézs - AZA6NL

//A beadandóhoz használt névtér
namespace OAF
{
	//Az OrderedSet típus saját iterátora egy STL kompatibilis bidirectional iterátor
	class OrderedSetIterator;

	//A halmazt reprezenáló osztály
	class OrderedSet
	{
		//Az OrderedSet osztály barátjául fogadja iterátor osztályát az OrderedSetIterator
		friend class OrderedSetIterator;
		
		//Fontos a Legkisebb jogosultság elve
		private:
			//A halmaz elemszáma privát érték.
			size_t _size;
		
			//A láncolt lista egy elemének reprezentációja az OSNode.
			//Csak az OrderedSet és barátaai használhatják.
			//Konstruálható üresen és paraméterezve.
			struct OSNode
			{
				OSNode();
				OSNode(OSNode*, OSNode*, int);
				OSNode* next;
				OSNode* prev;
				int value;
			};
			
			//A fejelemre mutató pointer
			OSNode* _head;
		
		public:
			/*Az OrderedSetIterator alkalmas konstansok kezelésére.
			A típushoz definiálunk külön szabványos nevű iterátort,
			így szabványos STL formában hívható: OAF::OrderedSet::iterator*/
			typedef OrderedSetIterator iterator;
			typedef OrderedSetIterator const_iterator;
		
		//Konstruktorok az OrderedSet-hez
			//Üres konstruktor
			OrderedSet();
			//Egy elemű halmaz létrehozása
			OrderedSet(int);
			//Halmaz létrehozása tömbből
			OrderedSet(int*, int);
			//Halmaz létrehozása vektorból
			OrderedSet(std::vector<int>&);
			//Halmaz létrehozása std::set-ből
			OrderedSet(std::set<int>&);
			//Másoló konstruktor
			OrderedSet(const OrderedSet&);
		
		//Alap műveletek	-	Az STD::SET alapján
			//ITERATOR - A kezdőelemre mutató iterátort ad!
			iterator begin();
			const_iterator begin() const;
			//Minden elemet töröl
			void clear();
			//Megadja, hogy a halmaz üres-e
			bool empty() const;
			//ITERATOR - Az utolsó elemre mutató iterátorral tér visszaad
			iterator end();
			const_iterator end() const;
			//Egy elemet töröl
			void erase(const int&);
			//Megkeres egy elemet és visszaad egy rámutató iterátort
			iterator find(const int&) const;
			//Egy elem hozzáasdása létező listához
			void insert(const int);
			//Megadja, hogy egy szám eleme-e a halmaznak
			bool isElement(int) const;
			//Megadja az elemszámot
			size_t size() const;

		//Kívánt műveletek
			//Két halmaz uniója
			OrderedSet uni(const OrderedSet&) const;
			//Két halmaz különbsége
			OrderedSet min(const OrderedSet&) const;
			//OrderedSet és std::set uniója
			OrderedSet uni(const std::set<int>&) const;
			//OrderedSet és std::set különbsége
			OrderedSet min(const std::set<int>&) const;
		
		//Operátorok
			//Két halmaz uniója + operátorral. Kommutatív.
			OrderedSet operator+ (const OrderedSet&) const;
			//Két halmaz különbsége - operátorral. Kommutatív.
			OrderedSet operator- (const OrderedSet&) const;
			
			//OrderedSet és std::set uniója +operátorral.
			OrderedSet operator+ (const std::set<int>&) const;
			//OrderedSet és std::set különbsége - operátorral.
			OrderedSet operator- (const std::set<int>&) const;
			//std::set és OrderedSet különbsége + operátorral. A kommutatívitás miatt szügséges.
			friend OrderedSet operator+ (std::set<int> const&, const OrderedSet&);
			//std::set és OrderedSet különbsége - operátorral. A kommutatívitás miatt szügséges.
			friend OrderedSet operator- (std::set<int> const&, const OrderedSet&);
			
			//|insert| művelet a következő formában: SET + 5 vagy 5 + SET. Kommutatív.
			OrderedSet operator+ (const int) const;
			friend OrderedSet operator+ (const int, const OrderedSet&);
			//|erase| művelet a következő formában: SET - 5 vagy 5 - SET. Kommutatív.
			OrderedSet operator- (const int) const;
			friend OrderedSet operator- (const int , const OrderedSet&);
			//|insert| művelet a következő formában: SET += 5
			OrderedSet& operator+= (const int);
			//|erase| művelet a következő formában: SET -= 5
			OrderedSet& operator-= (const int);
			
			//A rendezett halmaz tartalmának átültetése ostream-be
			friend std::ostream& operator<< (std::ostream&, const OrderedSet&);
			//A rendezett halmaz beolvasása egyben  ostream-ből
			friend std::istream& operator>> (std::istream&, OrderedSet&);
			
			//Értékadó operátor (Másoló konstruktor)
			OrderedSet& operator=(const OrderedSet&);
			
			//Két halmaz összehasonlítása. Kommutatív.
			bool operator!=(OrderedSet const&);
			bool operator==(OrderedSet const&);
			
			//OrderedSet és std::set összehasonlítása Kommutatív.
			bool operator!=(std::set<int> const&);
			bool operator==(std::set<int> const&);
			friend bool operator!=(std::set<int> const&, OrderedSet const&);
			friend bool operator==(std::set<int> const&, OrderedSet const&);
			
			//Destruktor
			~OrderedSet();
	};
	
	/*STL kompatibilis bidirectional iterátor az OrderedSet típusjoz. Az std::iterator-ból származik.
	Az STL által a bidirectional iterator-hoz előírt metódusai implementálva vannak.*/
	class OrderedSetIterator : std::iterator< std::bidirectional_iterator_tag, int >
	{
		public:
			//Az aktuálisan mutatott listaelemre mutató pointer
			OAF::OrderedSet::OSNode* curent;
			
			//A konstrktorok
			OrderedSetIterator();
			OrderedSetIterator(OrderedSet);
			OrderedSetIterator(OAF::OrderedSet::OSNode*);
			
			//Az STL által a bidirectional iterator-hoz előírt operátorok, a dokumentáció szerint.
			bool operator== (OAF::OrderedSet::iterator const&);
			bool operator!= (OAF::OrderedSet::iterator const&);
			int& operator*() const;
			int* operator->() const;
			OrderedSetIterator& operator++ ();
			OrderedSetIterator&  operator++ (int);
			OrderedSetIterator& operator-- ();
			OrderedSetIterator&  operator-- (int);

			//OrderedSetIterator* operator++ (int);  												//a++ postfix++
			//OrderedSetIterator& operator=(const OrderedSetIterator&); 							//b = a
			//OrderedSetIterator& operator=(const OAF::OrderedSet::OSNode&);//b = node
			//OrderedSetIterator* operator-- (int);  												//a-- postfix--
			//operator OrderedSetIterator() const;												//konstansság
	};
}
#endif
