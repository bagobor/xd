#ifndef H_XD_AUDIO_SOUND
#define H_XD_AUDIO_SOUND

#include <xd/config.hpp>
#include <xd/ref_counted.hpp>
#include <boost/noncopyable.hpp>
#include <boost/intrusive_ptr.hpp>
#include <string>

#pragma warning(disable: 4275)

namespace xd
{
	namespace detail
	{
		struct sound_handle;
	}

	class XD_API sound : public xd::ref_counted, public boost::noncopyable
	{
	public:
		typedef boost::intrusive_ptr<sound> ptr;

		sound(const std::string& filename);
		virtual ~sound();

		void play();
		void pause();
		void stop();

		bool playing();
		bool paused();
		bool stopped();

		void set_offset(float offset);
		void set_volume(float volume);
		void set_pitch(float pitch);
		void set_looping(bool looping);
		void set_loop_point(float time);

		float get_offset();
		float get_volume();
		float get_pitch();
		bool get_looping();
		float get_loop_point();

	private:
		detail::sound_handle *m_handle;
	};
}

#endif
