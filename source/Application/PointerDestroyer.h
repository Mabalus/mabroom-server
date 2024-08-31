#ifndef APPLICATION_POINTER_DESTROYER_H
#define APPLICATION_POINTER_DESTROYER_H

namespace application {

	template <typename T>
	struct pointerDestroyer {
		void operator()(T *pt_object) const {
			delete pt_object;
		}
	};

}

#endif
