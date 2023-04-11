#pragma once
class Bin {
private:
	bool mb0 : 1;
	bool mb1 : 1;
	bool mb2 : 1;
	bool mb3 : 1;
	bool mb4 : 1;
	bool mb5 : 1;
	bool mb6 : 1;
	bool mb7 : 1;
public:
	void Show() const;
	friend union Byte;
	void ShowSmb(int val) const;
	void Edit(int val, int z);
};

class Hex {
	unsigned char mx0 : 4;//максимум до 16
	unsigned char mx1 : 4;
public:
	void Show() const;
	void ShowSmb(int val) const;
	friend union Byte;
	void Edit(int val, int z);
};

class Oct {
	unsigned char mo0 : 3;
	unsigned char mo1 : 3;
	unsigned char mo2 : 2;
public:
	void Show() const;
	friend union Byte;
	void ShowSmb(int val) const;
	void Edit(int val, int z);
};

class Dec {
	unsigned char md0;
public:
	void Show() const;
	friend union Byte;
};
union Byte {
private:
	Hex mhex;
	Oct moct;
	Bin mbin;
	Dec mdec;
	unsigned char m_val;
public:
	Byte(unsigned char);
	void ShowHex() const { mhex.Show(); };
	void ShowOct() const { moct.Show(); };
	void ShowBin() const { mbin.Show(); };
	void ShowDec() const { mdec.Show(); };
	void ShowSmbHex(int val) const { mhex.ShowSmb(val); };
	void ShowSmbBin(int val) const { mbin.ShowSmb(val); }
	void ShowSmbOct(int val) const { mbin.ShowSmb(val); };
	void EditHex(int val, int z) { mhex.Edit(val, z); };
	void EditBin(int val, int z) { mbin.Edit(val, z); };
	void EditOct(int val, int z) { moct.Edit(val, z); };
};