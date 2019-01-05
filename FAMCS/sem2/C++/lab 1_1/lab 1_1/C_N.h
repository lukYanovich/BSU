#pragma once

namespace Alex
{
	class C_N
	{
	private:
		double Re;
		double Im;
	public:
		C_N(){}
		~C_N(){}
		C_N(double a, double b) { Re = a;  Im = b; }

		double GetIm() const { return Im; }
		double GetRe() const { return Re; }
		void SetIm(double a) { Im = a; }
		void SetRe(double a) { Re = a; }

		const C_N plus(const C_N& a) const;
		const C_N minus(const C_N& a) const;
		const C_N umn(const C_N& a) const;
		const C_N del(const C_N& a) const;
		const C_N srav(const C_N& a) const;
	};
}