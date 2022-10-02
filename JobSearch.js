// import '@fortawesome/fontawesome-free/css/all.min.css';
// import './JobSearch.css'
// import { searchGig } from '../../app/actions/searchActions';
// import { connect } from 'react-redux';

// export function JobSearch() {

//     onChange = (e) => {
//         this.props.searchGig(e.target.value);
//     }

//     return <>
//         <p>Find Gigs</p>
//         {/* <a href="https://gigvistas.com"> Assignment Details</a> */}
//         <div className="container">
//         <div className="search-box">
//             <input type="text" className="search-input" placeholder="Search.." onChange={this.onChange}/>
//             <button type="submit" className="search-button">
//                 <i className="fas fa-search"></i>
//             </button>
//         </div>
//         </div>
//     </>
// }

// const mapStateToProps = state => ({
//     text : state.gigs.text
// })

// export default connect(mapStateToProps, {searchGig})(JobSearch);

import React, { Component } from 'react'
import '@fortawesome/fontawesome-free/css/all.min.css';
import './JobSearch.css'
import { searchGig } from '../../app/actions/searchActions';
import { connect } from 'react-redux';


export class JobSearch extends Component {

    onChange = e => {
        const str = e.target.value;
        console.log(str);
        searchGig(str);
    }

  render() {
    return <>
        <p>Find Gigs</p>
        {/* <a href="https://gigvistas.com"> Assignment Details</a> */}
        <div className="container">
        <div className="search-box">
            <input type="text" className="search-input" placeholder="Search.." value={this.value} onChange={this.onChange}/>
            <button type="submit" className="search-button">
                <i className="fas fa-search"></i>
            </button>
        </div>
        </div>
    </>
  }
}

const mapStateToProps = state => ({
    text : state.gigs.text
})

export default connect(mapStateToProps, {searchGig})(JobSearch);