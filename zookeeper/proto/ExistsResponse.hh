// File generated by hadoop record compiler. Do not edit.

#ifndef ExistsResponse_HH_
#define ExistsResponse_HH_

#include "Efc.hh"
#include "../../jute/inc/ERecord.hh"
#include "../../jute/inc/EBinaryInputArchive.hh"
#include "../../jute/inc/EBinaryOutputArchive.hh"
#include "../../jute/inc/ECsvOutputArchive.hh"
#include "../data/Stat.hh"

namespace efc {
namespace ezk {

class ExistsResponse: public ERecord {
public:
	sp<Stat> stat;

	ExistsResponse() {
	}
	ExistsResponse(sp<Stat> stat) {
		this->stat = stat;
	}
	sp<Stat> getStat() {
		return stat;
	}
	void setStat(sp<Stat> m_) {
		stat = m_;
	}
	virtual void serialize(EOutputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(this, tag);
		a_->writeRecord(stat.get(), "stat");
		a_->endRecord(this, tag);
	}
	virtual void deserialize(EInputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(tag);
		stat = new Stat();
		a_->readRecord(stat.get(), "stat");
		a_->endRecord(tag);
	}
	virtual EString toString() {
		try {
			EByteArrayOutputStream s;
			ECsvOutputArchive a_(&s);
			a_.startRecord(this, "");
			a_.writeRecord(stat.get(), "stat");
			a_.endRecord(this, "");
			s.write('\0');
			return (char*) s.data();
		} catch (EThrowable& ex) {
			ex.printStackTrace();
		}
		return "ERROR";
	}
	void write(EDataOutput* out) THROWS(EIOException) {
		EBinaryOutputArchive archive(out);
		serialize(&archive, "");
	}
	void readFields(EDataInput* in) THROWS(EIOException) {
		EBinaryInputArchive archive(in);
		deserialize(&archive, "");
	}
	virtual int compareTo(EObject* peer_) THROWS(EClassCastException) {
		ExistsResponse* peer = dynamic_cast<ExistsResponse*>(peer_);
		if (!peer) {
			throw EClassCastException(__FILE__, __LINE__,
					"Comparing different types of records.");
		}
		int ret = 0;
		ret = stat->compareTo(peer->stat.get());
		if (ret != 0)
			return ret;
		return ret;
	}
	virtual boolean equals(EObject* peer_) {
		ExistsResponse* peer = dynamic_cast<ExistsResponse*>(peer_);
		if (!peer) {
			return false;
		}
		if (peer_ == this) {
			return true;
		}
		boolean ret = false;
		ret = stat->equals(peer->stat.get());
		if (!ret)
			return ret;
		return ret;
	}
	virtual int hashCode() {
		int result = 17;
		int ret;
		ret = stat->hashCode();
		result = 37 * result + ret;
		return result;
	}
	static EString signature() {
		return "LExistsResponse(LStat(lllliiiliil))";
	}
};

} /* namespace ezk */
} /* namespace efc */
#endif /* ExistsResponse_HH_ */