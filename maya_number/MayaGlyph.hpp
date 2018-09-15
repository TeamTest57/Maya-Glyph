#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace maya {

	//通常の数字をマヤ数字に変換する
	template <typename NormalNum, typename MayaNum>
	void mayaNumber(NormalNum num_, std::vector<MayaNum>& maya_num_) {
		//各位の上限値
		constexpr NormalNum num_20 = (NormalNum)20;
		constexpr NormalNum num_18 = (NormalNum)18;
		constexpr NormalNum num_0 = (NormalNum)0;
		//要素を消去
		maya_num_.clear();
		//元の数字が0以下の場合
		if (num_ <= num_0) {
			maya_num_.emplace_back((MayaNum)0);
			return;
		}
		//1桁目を選定 (0~19)
		maya_num_.emplace_back((MayaNum)(num_ % num_20));
		if ((num_ /= num_20) == 0) return;
		//2桁目を選定 (0~17)
		maya_num_.emplace_back((MayaNum)(num_ % num_18));
		if ((num_ /= num_18) == 0) return;
		//3桁目以降を選定 (0~19)
		while (true) {
			maya_num_.emplace_back((MayaNum)(num_ % num_20));
			if ((num_ /= num_20) == 0) return;
		}
	}
	template <typename MayaNum>
	void mayaNumber(const float num_, std::vector<MayaNum>& maya_num_) {
		mayaNumber((unsigned long long)num_, maya_num_);
	}
	template <typename MayaNum>
	void mayaNumber(const double num_, std::vector<MayaNum>& maya_num_) {
		mayaNumber((unsigned long long)num_, maya_num_);
	}
	template <typename MayaNum>
	void mayaNumber(const long double num_, std::vector<MayaNum>& maya_num_) {
		mayaNumber((unsigned long long)num_, maya_num_);
	}
	//マヤ数字を出力する
	template <typename MayaNum>
	void mayaNumberOutput(const std::vector<MayaNum>& maya_num_) {
		for (size_t i = 0; i < maya_num_.size(); ++i)
			std::cout << maya_num_[i] << ',';
	}
	template <>
	void mayaNumberOutput(const std::vector<unsigned char>& maya_num_) {
		for (size_t i = 0; i < maya_num_.size(); ++i)
			std::cout << (int)maya_num_[i] << ',';
	}
	template <>
	void mayaNumberOutput(const std::vector<signed char>& maya_num_) {
		for (size_t i = 0; i < maya_num_.size(); ++i)
			std::cout << (int)maya_num_[i] << ',';
	}
	//通常の数字をマヤ数字に変換して出力する
	template <typename NormalNum, typename MayaNum>
	void mayaNumberOutput(const NormalNum& num_, std::vector<MayaNum>& maya_num_) {
		mayaNumber(num_, maya_num_);
		mayaNumberOutput(maya_num_);
	}
	//通常の数字をマヤ数字に変換して出力する
	template <typename NormalNum>
	void mayaNumberOutput(const NormalNum& num_) {
		std::vector<unsigned char> maya_num_;
		mayaNumber(num_, maya_num_);
		mayaNumberOutput(maya_num_);
	}

	//マヤ数字を文字形式に変換する
	template <typename MayaNum>
	void mayaNumberUTF(const std::vector<MayaNum>& maya_num_, std::u32string& str_) {
		str_.clear();
		for (size_t i = maya_num_.size(); i > 0;)
			str_.push_back((char32_t)((MayaNum)0x1D2E0 + maya_num_[--i]));
	}
	template <typename MayaNum>
	void mayaNumberUTF(const std::vector<MayaNum>& maya_num_, std::u16string& str_) {
		str_.clear();
		for (size_t i = maya_num_.size(); i > 0;) {
			str_.push_back((char16_t)0xD834);
			str_.push_back((char16_t)((MayaNum)0xDEE0 + maya_num_[--i]));
		}
	}
	template <typename MayaNum>
	void mayaNumberUTF(const std::vector<MayaNum>& maya_num_, std::string& str_) {
		str_.clear();
		for (size_t i = maya_num_.size(); i > 0;) {
			str_.push_back((char)0xF0);
			str_.push_back((char)0x9D);
			str_.push_back((char)0x8B);
			str_.push_back((char)((MayaNum)0xA0 + maya_num_[--i]));
		}
	}
	//通常の数字をマヤ数字の文字形式に変換する
	template <typename NormalNum, typename MayaNum>
	void mayaNumberUTF(const NormalNum& num_, std::vector<MayaNum>& maya_num_, std::string& str_) {
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum>
	void mayaNumberUTF(const NormalNum& num_, std::string& str_) {
		std::vector<unsigned char> maya_num_;
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum, typename MayaNum>
	void mayaNumberUTF(const NormalNum& num_, std::vector<MayaNum>& maya_num_, std::u16string& str_) {
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum>
	void mayaNumberUTF(const NormalNum& num_, std::u16string& str_) {
		std::vector<unsigned char> maya_num_;
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum, typename MayaNum>
	void mayaNumberUTF(const NormalNum& num_, std::vector<MayaNum>& maya_num_, std::u32string& str_) {
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
	template <typename NormalNum>
	void mayaNumberUTF(const NormalNum& num_, std::u32string& str_) {
		std::vector<unsigned char> maya_num_;
		mayaNumber(num_, maya_num_);
		mayaNumberUTF(maya_num_, str_);
	}
}