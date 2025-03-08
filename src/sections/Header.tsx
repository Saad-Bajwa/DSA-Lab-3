import ArrowRight from '../assets/arrow-right.svg';
import Logo from '@/assets/logosaas.png';
import Image from 'next/image';
import Menu from '@/assets/menu.svg';
export const Header = () => {
  return <header className='sticky top-0 backdrop-blur-sm z-20'>
    <div className="flex justify-center items-center bg-black text-white py-3 text-sm gap-3">
      <p className='text-white/60 hidden md:block'>Streamline your workflow and boost your productivity</p>
      <div className='inline-flex items-center gap-1'>
        <p>Get started for free</p>
        <ArrowRight className='h-4 w-4 inline-flex justify-center items-center' />
      </div>
    </div>
    <div className='py-5'>
      <div className='container'>
        <div className='flex items-center justify-between'>
          <Image src={Logo} alt="Saas Logo" height={40} width={40} />
          <Menu className='w-5 h-5 md:hidden' />
          <nav className='hidden md:flex gap-6 items-center text-black/60'>
            <a href='#'>About</a>
            <a href='#'>Features</a>
            <a href='#'>Customers</a>
            <a href='#'>Updates</a>
            <a href='#'>Help</a>
            <button className='btn btn-primary'>Get for free</button>
          </nav>
        </div>
      </div>
    </div>
  </header>
};
