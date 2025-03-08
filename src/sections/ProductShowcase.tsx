import ProductImage from '@/assets/product-image.png';
import PyramidImage from '@/assets/pyramid.png';
import TubeImage from '@/assets/tube.png';

import Image from 'next/image';
export const ProductShowcase = () => {
  return <section className='bg-gradient-to-b from-[#FFFFFF] to-[#D2DCFF] py-24 overflow-x-clip'>
    <div className='container'>
      <div className='max-w-[540px] mx-auto'>
        <div className='flex justify-center'>
          <div className='tag'>Boost your productivity</div>
        </div>
        <h2 className='title text-3xl md:text-[54px] md:leading-[60px] font-bold text-center mt-5'>A more effective way to track progress</h2>
        <p className='text-center text-[22px] leading-[30px] tracking-tight text-[#010D3E] mt-5'>Celebrate the joy of accomplishment with an app designed to track your progress and motivate your efforts.</p>
      </div>
    </div>
    <div className='relative'>
      <Image src={ProductImage} alt="ProductImage" className='mt-5' />
      <Image src={PyramidImage} alt="PyramidImage" className='hidden md:block absolute -right-36 -top-32' width={262} height={262} />

      <Image src={TubeImage} alt="TubeImage" className='hidden md:block absolute bottom-24 -left-36' width={262} height={248} />
    </div>
  </section>
};
