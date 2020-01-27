class Case {

public:

	bool canAdd(Case& box) {
		if (box.getStatus() == -1) {
			return false;
		}
		else if (box.getStatus() == this->getStatus()) {
			return false;
		}

		else {
			return true;
		}
	}

	int getStatus() {
		return this->status;
	}

	void setStatus(int var) {
		this->status = var;
	}

private:
	int status;
};