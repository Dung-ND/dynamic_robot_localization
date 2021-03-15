#pragma once

/**\file normal_distributions_transform_2d.h
 * \brief Description...
 *
 * @version 1.0
 * @author Carlos Miguel Correia da Costa
 */

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <includes>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// std includes
#include <memory>
#include <string>

// PCL includes
#include <pcl/registration/ndt_2d.h>
#include <pcl/registration/registration.h>

// external libs includes
#include <Eigen/Core>

// project includes
#include <dynamic_robot_localization/cloud_matchers/cloud_matcher.h>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </includes>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

namespace dynamic_robot_localization {


// #################################################################   NormalDistributionsTransform2DDetailed   ################################################################
template <typename PointSource, typename PointTarget>
class NormalDistributionsTransform2DDetailed: public pcl::NormalDistributionsTransform2D<PointSource, PointTarget> {
	public:
		using Ptr = std::shared_ptr< NormalDistributionsTransform2DDetailed<PointSource, PointTarget> >;
		using ConstPtr = std::shared_ptr< const NormalDistributionsTransform2DDetailed<PointSource, PointTarget> >;

		inline int getNumberOfRegistrationIterations() { return pcl::Registration<PointSource, PointTarget>::nr_iterations_; }
		virtual void computeTransformation(pcl::PointCloud<PointSource> &output, const Eigen::Matrix4f &guess) {
			pcl::Registration<PointSource, PointTarget>::nr_iterations_ = 0;
			pcl::Registration<PointSource, PointTarget>::converged_ = false;
			pcl::NormalDistributionsTransform2D<PointSource, PointTarget>::computeTransformation(output, guess);
		}
};

// #####################################################################   NormalDistributionsTransform2D   ####################################################################
/**
 * \brief Description...
 */
template <typename PointT>
class NormalDistributionsTransform2D : public CloudMatcher<PointT> {
	// ========================================================================   <public-section>   ===========================================================================
	public:
		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <usings>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		using Ptr = std::shared_ptr< NormalDistributionsTransform2D<PointT> >;
		using ConstPtr = std::shared_ptr< const NormalDistributionsTransform2D<PointT> >;
		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </usings>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <constructors-destructor>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		NormalDistributionsTransform2D() {}
		virtual ~NormalDistributionsTransform2D() {}
		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </constructors-destructor>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <NormalDistributionsTransform2D-functions>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		virtual void setupConfigurationFromParameterServer(ros::NodeHandlePtr& node_handle, ros::NodeHandlePtr& private_node_handle, const std::string& configuration_namespace);
		virtual int getNumberOfRegistrationIterations();
		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </NormalDistributionsTransform2D-functions>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <gets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </gets>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <sets>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </sets>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	// ========================================================================   </public-section>  ===========================================================================

	// ========================================================================   <protected-section>   ========================================================================
	protected:
	// ========================================================================   </protected-section>  ========================================================================
};

} /* namespace dynamic_robot_localization */

#ifdef DRL_NO_PRECOMPILE
#include <dynamic_robot_localization/cloud_matchers/point_matchers/impl/normal_distributions_transform_2d.hpp>
#endif

